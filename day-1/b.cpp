#include <iostream>
using namespace std;

int main() {
    int t, l, k;
    int p, q;

    cin >> t >> l >> k;
    cin >> p >> q;

    int maksimal = 0;

    for (int i = 0; i <= l; i++) {
        int taliSisa = t - (i * 2);

        if (taliSisa < 0) {
            break;
        }

        int gelangKristal = taliSisa / 3;

        if (gelangKristal > k / 2) {
            gelangKristal = k / 2;
        }

        int keuntungan = (i * p) + (gelangKristal * q);

        if (keuntungan > maksimal) {
            maksimal = keuntungan;
        }
    }

    cout << maksimal;

    return 0;
}
