#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, d;
        cin >> n >> m >> d;

        int maxTowerSize = (d / m) + 1;
        cout << ((n + maxTowerSize - 1) / maxTowerSize) << "\n";
    }
    return 0;
}
