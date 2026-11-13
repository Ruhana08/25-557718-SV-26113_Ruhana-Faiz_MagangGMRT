import math
import matplotlib.pyplot as plt

femur = 18
tibia = 23

# femur = int(input('masukkan 2 angka terakhir NIU: '))
# tibia = int(input('masukkan 2 angka terakhir NIF: '))

sudut1 = float(input('masukkan sudut servo 1: '))
sudut2 = float(input('masukkan sudut servo 2: '))

servo1 = math.radians(sudut1)
servo2 = math.radians(sudut1 + sudut2)

x = femur * math.cos(servo1) + tibia * math.cos(servo2)
y = femur * math.sin(servo1) + tibia * math.sin(servo2)

print("Koordinat End-Effector:")
print("X =", round(x, 2), "cm")
print("Y =", round(y, 2), "cm")
