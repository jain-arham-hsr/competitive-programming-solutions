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
        vector<int> p(n);
        for (auto &x : p)
            cin >> x;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        int i = 0;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            while (i < n && p[i] != a[j])
                i++;
            if (i == n) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
