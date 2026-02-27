#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int consecZeros = 0;
        bool ok = true;
        for (int i = 0; i <= n; i++) {
            if (i < n && s[i] == '0')
                consecZeros++;
            else if (consecZeros == 1) {
                ok = false;
                break;
            } else {
                consecZeros = 0;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int lastSkipped = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                cout << (i + 1) << " ";
            else if (i != n - 1 && s[i + 1] == '0') {
                if (i != 0 && s[i - 1] == '1')
                    lastSkipped = i + 1;
                cout << (i + 2) << " ";
            } else {
                cout << lastSkipped << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
