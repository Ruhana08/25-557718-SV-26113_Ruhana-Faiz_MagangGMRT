#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long selisih = a - b;

    if (selisih == 0) {
        cout << 0;
    }
    else if (selisih % 2 != 0) {
        cout << -1;
    }
    else {
        long long perpindahan = selisih / 2;

        if (perpindahan < 0) {
            perpindahan = -perpindahan;
        }

        cout << (perpindahan + c - 1) / c;
    }

    return 0;
}
