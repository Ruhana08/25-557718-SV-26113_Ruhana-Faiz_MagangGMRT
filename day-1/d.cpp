#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int total = a + (b * 2) + (c * 3);

    if (total % 2 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
