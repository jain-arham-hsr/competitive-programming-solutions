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
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<int> b(n);
        for (auto &x : b)
            cin >> x;
        vector<int> rem(n);
        for (int i = 0; i < n; i++) {
            rem[i] = b[i] - a[i];
        }
        sort(rem.begin(), rem.end());
        int l = 0, r = n - 1;
        long long res = 0;
        while (l < r) {
            if (rem[l] + rem[r] < 0) {
                l++;
            } else {
                res++;
                l++;
                r--;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
