#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;
        vector<long long> b(n);
        for (auto &x : b)
            cin >> x;

        vector<long long> c(n);
        c[n - 1] = max(a[n - 1], b[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            c[i] = max(max(a[i], b[i]), c[i + 1]);
        }
        vector<long long> p(n);
        partial_sum(c.begin(), c.end(), p.begin());

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l == 0)
                cout << p[r] << " ";
            else
                cout << p[r] - p[l - 1] << " ";
        }
        cout << "\n";
    }
    return 0;
}
