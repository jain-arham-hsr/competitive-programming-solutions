#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        string binString;
        cin >> binString;
        int freeCoins = 0;
        int specialCoins = 0;
        for (int i = 0; i < n; i++) {
            if (binString[i] == '0')
                freeCoins += a[i];
            else
                specialCoins += a[i];
        }
        int res = freeCoins;
        if (specialCoins > c && freeCoins >= c) {
            res += specialCoins - c;
        }
        cout << res << "\n";
    }
}
