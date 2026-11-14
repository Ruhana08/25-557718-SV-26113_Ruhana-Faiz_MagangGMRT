#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>
#include <ESP32Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

Adafruit_MPU6050 mpu;

float yaw = 0;
float gyroZTerakhir = 0;

unsigned long waktuSebelumnya = 0;
unsigned long waktuPerubahanYaw = 0;
unsigned long waktuMulaiPIR = 0;

const int pinPIR = 27;
const int sudutTargetPIR = 160;
const unsigned long durasiPIR = 1000;

bool gerakanTerdeteksi = false;
bool pirSudahDiproses = false;
bool yawBergerak = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  pinMode(pinPIR, INPUT);

  servo1.attach(13, 1000, 2000);
  servo2.attach(14, 1000, 2000);
  servo3.attach(16, 1000, 2000);
  servo4.attach(17, 1000, 2000);
  servo5.attach(18, 1000, 2000);

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);

  if (!mpu.begin()) {
    Serial.println("MPU6050 tidak ditemukan!");

    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 berhasil terdeteksi!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  waktuSebelumnya = millis();
  waktuPerubahanYaw = millis();
}

void loop() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  unsigned long waktuSekarang = millis();

  float deltaTime =
    (waktuSekarang - waktuSebelumnya) / 1000.0;

  waktuSebelumnya = waktuSekarang;

  int statusPIR = digitalRead(pinPIR);

  float perubahanGyroZ =
    fabs(gyro.gyro.z - gyroZTerakhir);

  if (perubahanGyroZ > 0.01) {
    yaw += gyro.gyro.z * 180.0 / PI * deltaTime;

    yawBergerak = true;
    waktuPerubahanYaw = waktuSekarang;
  }

  gyroZTerakhir = gyro.gyro.z;

  if (yawBergerak &&
      waktuSekarang - waktuPerubahanYaw >= 1000) {

    yaw = 0;
    yawBergerak = false;
  }

  yaw = constrain(yaw, -90, 90);

  float roll = atan2(
    accel.acceleration.y,
    accel.acceleration.z
  ) * 180.0 / PI;

  float pitch = atan2(
    -accel.acceleration.x,
    sqrt(
      accel.acceleration.y * accel.acceleration.y +
      accel.acceleration.z * accel.acceleration.z
    )
  ) * 180.0 / PI;

  int sudutServo1 = constrain(90 - roll, 0, 180);
  int sudutServo2 = constrain(90 - roll, 0, 180);
  int sudutServo3 = constrain(90 + pitch, 0, 180);
  int sudutServo4 = constrain(90 + pitch, 0, 180);

  int pwmServo1 = map(sudutServo1, 0, 180, 1000, 2000);
  int pwmServo2 = map(sudutServo2, 0, 180, 1000, 2000);
  int pwmServo3 = map(sudutServo3, 0, 180, 1000, 2000);
  int pwmServo4 = map(sudutServo4, 0, 180, 1000, 2000);

  if (statusPIR == HIGH && !pirSudahDiproses) {
    pirSudahDiproses = true;
    gerakanTerdeteksi = true;
    waktuMulaiPIR = waktuSekarang;

    Serial.println("Gerakan terdeteksi! Semua servo bergerak.");
  }

  if (statusPIR == LOW) {
    pirSudahDiproses = false;
  }

  if (gerakanTerdeteksi) {

    servo1.write(sudutTargetPIR);
    servo2.write(sudutTargetPIR);
    servo3.write(sudutTargetPIR);
    servo4.write(sudutTargetPIR);
    servo5.write(sudutTargetPIR);

    if (waktuSekarang - waktuMulaiPIR >= durasiPIR) {

      servo1.write(90);
      servo2.write(90);
      servo3.write(90);
      servo4.write(90);
      servo5.write(90);

      yaw = 0;
      yawBergerak = false;

      gerakanTerdeteksi = false;

      Serial.println("Semua servo kembali ke posisi awal.");
    }
  }

  else {

    int sudutServo5 = constrain(90 + yaw, 0, 180);

    servo1.write(sudutServo1);
    servo2.write(sudutServo2);
    servo3.write(sudutServo3);
    servo4.write(sudutServo4);
    servo5.write(sudutServo5);
  }

  Serial.print("Roll: ");
  Serial.print(roll);

  Serial.print(" | Pitch: ");
  Serial.print(pitch);

  Serial.print(" | Gyro Z: ");
  Serial.print(gyro.gyro.z);

  Serial.print(" | Yaw: ");
  Serial.println(yaw);

  Serial.print("PWM Servo 1: ");
  Serial.print(pwmServo1);

  Serial.print(" | PWM Servo 2: ");
  Serial.print(pwmServo2);

  Serial.print(" | PWM Servo 3: ");
  Serial.print(pwmServo3);

  Serial.print(" | PWM Servo 4: ");
  Serial.println(pwmServo4);

  delay(20);
}
