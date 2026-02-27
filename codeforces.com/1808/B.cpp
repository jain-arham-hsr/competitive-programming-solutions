#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cols(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> cols[j][i];
            }
        }
        long long res = 0;
        for (auto &x : cols) {
            sort(x.begin(), x.end());
            long long sum = 0;
            for (long long i = 0; i < n; i++) {
                res += x[i] * i - sum;
                sum += x[i];
            }
        }
        cout << res << "\n";
    }
    return 0;
}
