#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> b(m);
        for (auto &x : b)
            cin >> x;
        sort(b.begin(), b.end());
        vector<int> a(q);
        for (auto &x : a)
            cin >> x;
        for (int i = 0; i < q; i++) {
            int d = a[i];
            int left = -1, right = m;
            while (left < right - 1) {
                int mid = left + (right - left) / 2;
                if (b[mid] > d) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            int t1 = left > -1 ? b[left] : 0;
            int t2 = right < m ? b[right] : n + 1;
            int f = (left > -1) + (right < m);
            int space = t2 - t1 - 1;
            cout << ((space + f - 1) / f) << "\n";
        }
    }
    return 0;
}
