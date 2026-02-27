#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (n % 9 == 0) {
            n /= 9;
            long long factor = 0;
            for (int i = 0; i <= log10(n); i++) {
                factor += pow(10, i);
            }
            int count = 9;
            while (n > 0 && factor > 0) {
                if (n >= factor && count > 0) {
                    n -= factor;
                    count--;
                } else {
                    factor /= 10;
                    count = 9;
                }
            }
            if (n > 0)
                cout << 0 << "\n";
            else
                cout << 10 << "\n";
        } else
            cout << 0 << "\n";
    }
    return 0;
}
