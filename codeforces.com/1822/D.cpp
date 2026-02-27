#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n > 1 && n % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cout << n - i << " ";
            } else {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
