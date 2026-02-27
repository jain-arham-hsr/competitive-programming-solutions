#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = i & x;
        }
        int orVal = 0;
        for (int i = 0; i < n; i++) {
            orVal |= res[i];
        }
        if (orVal != x)
            res[n - 1] = x;
        for (auto &x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
