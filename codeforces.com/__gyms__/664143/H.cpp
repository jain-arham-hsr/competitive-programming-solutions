#include <bits/stdc++.h>
using namespace std;

long long modBy = 1e9 + 7;

long long calc(long long m, long long n) {
    if (n == 1)
        return (2 * m - 2);
    else if (n == 2)
        return (2 * calc(m, n - 1) - 1);
    else if (n == 3)
        return (2 * calc(m, n - 1) - 1);
    else if (n == 4)
        return (3 * calc(m, n - 1) - 2);
    long long val = calc(m, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        // code here
    }
    return 0;
}
