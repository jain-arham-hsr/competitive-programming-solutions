#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "1\n";
        cout << a;
    } else if (a > b) {
        cout << "3\n";
        cout << b - 1 << " " << b << " " << 3 * a - 2 * b + 1;
    } else {
        cout << "3\n";
        cout << 3 * a - 2 * b - 1 << " " << b << " " << b + 1;
    }

    return 0;
}
