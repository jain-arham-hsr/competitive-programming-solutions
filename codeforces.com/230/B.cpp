#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m = 1e6;
    vector<bool> isPrime(m + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i <= m; i++) {
        if (!isPrime[i])
            continue;
        for (long long j = i * i; j <= m; j += i) {
            isPrime[j] = false;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (sqrt(n) != floor(sqrt(n))) {
            cout << "NO\n";
            continue;
        }
        if (isPrime[sqrt(n)])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
