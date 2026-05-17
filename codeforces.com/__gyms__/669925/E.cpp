#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> tiles(n);
        for (auto &x : tiles)
            cin >> x;
        int i = 0;
        int l = 0;
        for (; i < n; i++) {
            if (l == k)
                break;
            if (tiles[i] == tiles[0])
                l++;
        }
        if (l < k) {
            cout << "NO\n";
            continue;
        }
        if (tiles[0] == tiles[n - 1]) {
            cout << "YES\n";
            continue;
        }
        int lcount = 0;
        for (; i < n; i++) {
            if (tiles[i] == tiles[n - 1])
                lcount++;
        }
        cout << (lcount >= k ? "YES\n" : "NO\n");
    }
    return 0;
}
