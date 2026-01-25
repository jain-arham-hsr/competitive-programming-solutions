#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int s, m, k;
        cin >> s >> k >> m;

        if (k >= s || (m / k) % 2 == 0) {
            cout << max(0, s - (m % k)) << "\n";
        } else {
            cout << k - (m % k) << "\n";
        }
    }
    return 0;
}
