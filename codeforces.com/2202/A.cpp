#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if ((x - 2 * y) < 0 || (x + 4 * y) < 0 || (x - 2 * y) % 3 != 0 ||
            (x + 4 * y) % 3 != 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
