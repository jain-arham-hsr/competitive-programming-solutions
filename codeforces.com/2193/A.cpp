#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, s, x;
        cin >> n >> s >> x;
        int t = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            t += num;
        }
        if (t <= s && (s - t) % x == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
