#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (auto &val : c)
        cin >> val;

    vector<int> dp(x + 1);

    dp[0] = 1;

    for (auto val : c) {
        for (int i = 0; i <= x; i++) {
            if (i + val <= x)
                dp[i + val] = (dp[i + val] + dp[i]) % MOD;
        }
    }

    cout << dp[x];

    return 0;
}
