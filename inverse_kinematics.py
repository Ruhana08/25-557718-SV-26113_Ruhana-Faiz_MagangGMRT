import math
import matplotlib.pyplot as plt

femur = 18
tibia = 23

# femur = int(input('masukkan 2 angka terakhir NIU: '))
# tibia = int(input('masukkan 2 angka terakhir NIF: '))

x = float(input('masukkan koordinat x: '))
y = float(input('masukkan koordinat y: '))

cos_theta2 = (x**2 + y**2 - femur**2 - tibia**2) / (2 * femur * tibia)

if -1 <= cos_theta2 <= 1:
    theta2 = math.acos(cos_theta2)

    theta1 = math.atan2(y, x) - math.atan2(
        tibia * math.sin(theta2),
        femur + tibia * math.cos(theta2)
    )

    servo1 = math.degrees(theta1)
    servo2 = math.degrees(theta2)

    print("Sudut Servo 1 =", round(servo1, 2), "derajat")
    print("Sudut Servo 2 =", round(servo2, 2), "derajat")

else:
    print("Target berada di luar jangkauan robot.")

