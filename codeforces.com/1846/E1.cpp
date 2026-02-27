#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 1e6 + 1;
    vector<bool> isPossible(n + 1);

    for (long long i = 2; i <= n; i++) {
        long long p = 3;
        long long val = (pow(i, p) - 1) / (i - 1);
        while (val <= n) {
            val = (pow(i, p) - 1) / (i - 1);
            if (val <= n) {
                isPossible[val] = true;
            }
            p++;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        cout << (isPossible[k] ? "YES\n" : "NO\n");
    }
    return 0;
}
