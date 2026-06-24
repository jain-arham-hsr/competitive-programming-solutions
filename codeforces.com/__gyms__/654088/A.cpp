#include <bits/stdc++.h>
using namespace std;

long long modBy = 1000000007;

long long binaryExponentiation(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binaryExponentiation(a, b / 2) % modBy;
    res *= res;
    if (b % 2 != 0)
        res *= a % modBy;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << ((binaryExponentiation(3, n) % modBy -
              3 * binaryExponentiation(2, n) % modBy + 3) +
             modBy) %
                modBy;

    return 0;
}
