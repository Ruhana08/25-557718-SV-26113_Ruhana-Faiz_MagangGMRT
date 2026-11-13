#include <iostream>
#include <string>
using namespace std;

int main() {
    int panjang, lebar;

    cout << "masukkan panjang: ";
    cin >> panjang;

    cout << "masukkan lebar: ";
    cin >> lebar;

    int luas = panjang * lebar;
    int keliling = 2 * (panjang + lebar);
    double rata_rata = (panjang + lebar) / 2.0;
    string nama_bangunan = "Persegi panjang";
    bool is_persegi = (panjang == lebar);

    cout << "Bangun: " << nama_bangunan << endl;
    cout << "Luas: " << luas << endl;
    cout << "Keliling: " << keliling << endl;
    cout << "rata-rata sisi: " << rata_rata << endl;
    cout << "is_persegi: " << is_persegi << endl;
    
    return 0;
}