#include <iostream>
using namespace std;

int main() {
    int x;
    int a[5];

    cin >> x;

    for (int i = 1; i <= 4; i++) {
        cin >> a[i];
    }

    int jumlah = 0;

    while (x != 0) {
        jumlah++;

        if (jumlah > 4) {
            break;
        }

        x = a[x];
    }

    if (jumlah == 4) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
