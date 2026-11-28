#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, l, r, x, y, z, b1, b2;
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
        long long mod = (1LL << 32);
        vector<long long> b(n);
        // long long b3=(((b1*x)%mod) + ((b2*y)%mod) +(z%mod))%mod;
        long long b3 =
            (((__int128)b1 * x) % mod + ((__int128)b2 * y) % mod + (z % mod)) %
            mod;
        b[0] = (b1);
        b[1] = (b2);

        if (n >= 3)
            b[2] = (b3);

        vector<long long> a(n);
        for (int i = 3; i < n; i++) {
            long long q =
                (((b[i - 2] * x) % mod) + ((b[i - 1] * y) % mod) + (z % mod)) %
                mod;
            b[i] = (q);
        }

        for (int i = 0; i < n; i++) {
            long long len = (r - l + 1);
            a[i] = (b[i] % len) + l;
        }

        // sort(a.begin(),a.end());

        // vector<long long>sufpmini(n,1e10);
        vector<long long> sufpmaxi(n, -1e18);

        sufpmaxi[n - 1] = a[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufpmaxi[i] = max(sufpmaxi[i + 1], a[i]);
        }

        set<long long> st;
        vector<long long> nextgre(n);
        for (int i = n - 1; i >= 0; i--) {
            if (!st.empty()) {
                auto it = st.upper_bound(a[i]);
                if (it == st.end()) {
                    nextgre[i] = -1e18;
                } else
                    nextgre[i] = *it;
            } else
                nextgre[i] = -1e18;
            st.insert(a[i]);
        }

        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && a[i] != a[i + 1]) {
                flag = true;
            }
        }
        if (!flag) {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        bool imp = true;
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                if (i + 1 < n && sufpmaxi[i + 1] > a[i] &&
                    sufpmaxi[i + 1] >= 0) {
                    ans = min(ans, sufpmaxi[i + 1] * a[i]);
                    imp = false;
                } else if (i + 1 < n && sufpmaxi[i + 1] < 0 &&
                           sufpmaxi[i + 1] > a[i]) {
                    ans = min(ans, sufpmaxi[i + 1] * a[i]);
                    imp = false;
                } else if (i + 1 < n && sufpmaxi[i + 1] < 0 &&
                           nextgre[i] > a[i]) {
                    ans = min(ans, nextgre[i] * a[i]);
                    imp = false;
                }
            } else if (a[i] == 0) {
                if (i + 1 < n && sufpmaxi[i + 1] > 0) {
                    ans = min(0LL, ans);
                    imp = false;
                }
            } else {
                if (nextgre[i] > a[i]) {
                    ans = min(ans, nextgre[i] * a[i]);
                    imp = false;
                }
            }
        }

        if (imp) {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }

        cout << ans << "\n";
    }
}
