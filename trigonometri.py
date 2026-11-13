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

# Visualisasi GUI/Plot menggunakan Matplotlib
x1 = femur * math.cos(servo1)
y1 = femur * math.sin(servo1)
plt.plot([0, x1, x], [0, y1, y], marker='o')
plt.text(x1/2, y1/2, 'Femur')
plt.text((x1+x)/2, (y1+y)/2, 'Tibia')

plt.grid(True)
plt.axis('equal')
plt.xlabel('X (cm)')
plt.ylabel('Y (cm)')
plt.title('Visualisasi Kaki Robot 2 DoF')
plt.show()