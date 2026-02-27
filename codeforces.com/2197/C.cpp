#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long p, q;
        cin >> p >> q;
        long long l = 1, r = min(p / 2, q / 3);
        bool bobWins = false;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (p - 2 * mid == q - 3 * mid) {
                bobWins = true;
                break;
            }
            if (p - 2 * mid < q - 3 * mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << (bobWins ? "Bob\n" : "Alice\n");
    }
    return 0;
}
