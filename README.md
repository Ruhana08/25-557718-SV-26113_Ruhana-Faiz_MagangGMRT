# Day 2 – Forward Kinematics 

## Identitas
- **Nama:** Ruhana Faiz Restiyanti
- **NIM:** 25/557718/SV/26223
- **Program:** Magang GMRT

## Deskripsi
Program ini dibuat menggunakan Python untuk menghitung pergerakan kaki robot sederhana dengan 2 Degree of Freedom (DoF).

Program terdiri dari Forward Kinematics untuk menghitung koordinat End-Effector berdasarkan sudut servo, serta Inverse Kinematics untuk menghitung sudut servo berdasarkan koordinat target.

## Spesifikasi Robot
- **Jumlah DoF:** 2
- **Femur:** Dapat diatur melalui input pengguna (default pengujian: 18 cm).
- **Tibia:** Dapat diatur melalui input pengguna (default pengujian: 23 cm).
- **Coxa:** 0 cm.

## Fitur Utama

### 1. Forward Kinematics
Menghitung koordinat X dan Y End-Effector berdasarkan sudut Servo 1 dan Servo 2.

### 2. Inverse Kinematics
Menghitung sudut Servo 1 dan Servo 2 berdasarkan koordinat X dan Y yang dimasukkan pengguna.

### 3. Visualisasi Matplotlib
Menampilkan gambaran posisi dan pergerakan kaki robot menggunakan Matplotlib.

## Bonus yang Dikerjakan
- [x] Mathematical Proof (perhitungan manual)
- [x] Visualisasi GUI/Plot menggunakan Matplotlib
- [x] Inverse Kinematics (IK)
- [ ] N-DoF
- [ ] Spatial Kinematics 3D
- [ ] Homogeneous Transformation

## Hasil Pengujian

Pengujian Forward Kinematics menggunakan:
- Servo 1 = 40°
- Servo 2 = 30°

Hasil koordinat:
- X = 21.65 cm
- Y = 33.18 cm

Pengujian Inverse Kinematics menggunakan koordinat:
- X = 21.66 cm
- Y = 33.18 cm

Hasil sudut:
- Servo 1 = 39.99°
- Servo 2 = 30.00°

## Library yang Digunakan
- `math` – untuk perhitungan trigonometri.
- `matplotlib` – untuk visualisasi grafik.

## Cara Menjalankan Program

Pastikan Python dan Matplotlib sudah terinstal.

Instal Matplotlib jika belum tersedia:

```bash
pip install matplotlib
```

Jalankan Forward Kinematics:

```bash
python trigonometri.py
```

Jalankan Inverse Kinematics:

```bash
python inverse_kinematics.py
```

Jalankan visualisasi GUI jika file `visualisasi_GUI.py` tersedia:

```bash
python visualisasi_GUI.py
```
