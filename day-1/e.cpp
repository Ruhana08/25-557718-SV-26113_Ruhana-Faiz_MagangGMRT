#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int total = a + b + c;
    string hasil = "";

    char terakhir = ' ';

    for (int i = 0; i < total; i++) {
        bool ditemukan = false;

        if (a > 0 && terakhir != 'A' &&
            a - 1 <= (total - i - 1 + 1) / 2) {

            hasil += 'A';
            a--;
            terakhir = 'A';
            ditemukan = true;
        }

        else if (b > 0 && terakhir != 'B' &&
                 b - 1 <= (total - i - 1 + 1) / 2) {

            hasil += 'B';
            b--;
            terakhir = 'B';
            ditemukan = true;
        }

        else if (c > 0 && terakhir != 'C' &&
                 c - 1 <= (total - i - 1 + 1) / 2) {

            hasil += 'C';
            c--;
            terakhir = 'C';
            ditemukan = true;
        }

        if (!ditemukan) {
            cout << -1;
            return 0;
        }
    }

    cout << hasil;

    return 0;
}
