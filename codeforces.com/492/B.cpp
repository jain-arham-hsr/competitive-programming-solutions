#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<int> pos(n);
    for (auto &x : pos)
        cin >> x;
    sort(pos.begin(), pos.end());
    int maxGap = 0;
    for (int i = 1; i < n; i++) {
        maxGap = max(maxGap, pos[i] - pos[i - 1]);
    }
    if (2 * (pos[0] - 0) > maxGap || 2 * (l - pos[n - 1]) > maxGap) {
        cout << fixed << setprecision(10)
             << (double)max(pos[0] - 0, l - pos[n - 1]) << "\n";
    } else {
        cout << fixed << setprecision(10) << (maxGap / 2.0) << "\n";
    }

    return 0;
}
