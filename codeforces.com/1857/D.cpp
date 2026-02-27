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
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;
        vector<long long> b(n);
        for (auto &x : b)
            cin >> x;
        long long maxVal = LLONG_MIN;
        vector<int> res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            long long c = a[i] - b[i];
            if (c > maxVal) {
                maxVal = c;
                res = {};
                res.push_back(i + 1);
            } else if (c == maxVal) {
                res.push_back(i + 1);
            }
        }
        sort(res.begin(), res.end());
        cout << res.size() << "\n";
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
