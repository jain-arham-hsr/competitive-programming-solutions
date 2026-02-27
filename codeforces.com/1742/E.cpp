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
        vector<long long> m(n + 1);
        long long maxStep = 0;
        for (int i = 1; i <= n; i++) {
            maxStep = max(a[i - 1], maxStep);
            m[i] = maxStep;
        }
        vector<long long> prefSum(n + 1);
        partial_sum(a.begin(), a.end(), prefSum.begin() + 1);
        for (int i = 0; i < q; i++) {
            int k;
            cin >> k;
            int ind = distance(m.begin(), upper_bound(m.begin(), m.end(), k));
            ind--;
            cout << prefSum[ind] << " ";
        }
        cout << "\n";
    }
    return 0;
}
