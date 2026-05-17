#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;
    k--;
    int bitInd = 0;
    long long res = 0;
    while (k > 0) {
        if (n == 0) {
            res = -1;
            break;
        }
        if (n & 1 > 0) {
            res += ((k & 1) << bitInd);
            k >>= 1;
        }
        bitInd++;
        n >>= 1;
    }

    cout << res;

    return 0;
}
