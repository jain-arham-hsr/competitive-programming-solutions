#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long x;
        cin >> x;
        vector<int> digits;
        digits.reserve(18);

        int p = 0;
        while (x > 0) {
            if (x < 10)
                p = x;
            digits.push_back(x % 10);
            x /= 10;
        }

        sort(digits.begin(), digits.end());

        vector<int> prefSum(digits.size());

        partial_sum(digits.begin(), digits.end(), prefSum.begin());

        int n = digits.size();

        int l = -1, r = n;
        while (l < r - 1) {
            int mid = l + (r - l) / 2;
            if ((digits[mid] < p && prefSum[mid] > 8) || prefSum[mid] > 9) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << (n - l - 1) << "\n";
    }
    return 0;
}
