#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long max = (1LL << n) - 1;
        long long currMask = (1LL << n) - 1;
        long long a = (1LL << n);
        for (int i = 0; i <= n; i++) {
            cout << currMask << " ";
            long long temp = currMask;
            while (temp + a < max) {
                temp += a;
                cout << temp << " ";
            }
            currMask >>= 1;
            if (currMask <= (max >> 2) && a > 2)
                a >>= 1;
        }
        cout << "\n";
    }
    return 0;
}
