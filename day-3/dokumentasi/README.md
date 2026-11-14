# Day 3 – ESP32 Motion Detection and Servo Control

## 1. Profile

- **Nama:** Ruhana Faiz Restiyanti
- **NIM:** 25/557718/SV/26223
- **Program:** Magang GMRT

## 2. Description

Proyek ini merupakan sistem berbasis ESP32 yang memanfaatkan sensor MPU6050 dan PIR untuk membaca perubahan orientasi serta mendeteksi gerakan dari lingkungan sekitar.

Sensor MPU6050 digunakan untuk memperoleh data accelerometer dan gyroscope yang membantu menentukan perubahan sudut Roll, Pitch, dan Yaw. Sensor PIR digunakan untuk mendeteksi gerakan objek di sekitar sensor.

Data sensor diproses oleh ESP32 untuk mengendalikan lima buah servo motor. Komunikasi antara ESP32 dan MPU6050 menggunakan protokol I2C, sedangkan pengendalian servo menggunakan sinyal PWM.

## 3. Feature Table

| Feature | Input (Sensor) | Output (Actuator) | Behavior |
|---|---|---|---|
| Roll | MPU6050 | Servo 1 dan Servo 2 | Servo merespons perubahan sudut Roll. |
| Pitch | MPU6050 | Servo 3 dan Servo 4 | Servo merespons perubahan sudut Pitch. |
| Yaw | Gyroscope MPU6050 | Servo 5 | Servo merespons perubahan rotasi Yaw. |
| External Motion | PIR | Sesuai konfigurasi program | Mendeteksi gerakan dari lingkungan sekitar. |

## 4. How to Run

### Wokwi Simulation

- **Wokwi Link:** [Masukkan link simulasi Wokwi di sini]

### Required Libraries

Pastikan library berikut tersedia:

- Wire
- Adafruit MPU6050
- Adafruit Unified Sensor
- ESP32Servo

### Running the Simulation

1. Buka link simulasi Wokwi.
2. Jalankan simulasi dengan menekan tombol Start Simulation.
3. Buka Serial Monitor untuk melihat data sensor dan nilai PWM servo.
4. Ubah orientasi atau gerakkan input sensor untuk menguji respons sistem.
5. Amati perubahan gerakan servo berdasarkan pembacaan sensor.

## 5. Project Files

- `Code/` – Berisi source code Arduino (`.ino`).
- `Screenshot/` – Berisi dokumentasi hasil pengujian.
- `Dokumentasi/` – Berisi README dan tautan pengumpulan.

