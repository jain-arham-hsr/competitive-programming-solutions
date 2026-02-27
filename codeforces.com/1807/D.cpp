#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        vector<int> prefOddCnt(n);
        prefOddCnt[0] = nums[0] % 2 == 1;
        for (int i = 1; i < n; i++) {
            prefOddCnt[i] = prefOddCnt[i - 1] + (nums[i] % 2 == 1);
        }
        bool totalOdd = prefOddCnt[n - 1] % 2 == 1;
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            bool isKEven = k % 2 == 0;
            l--;
            r--;
            int rangeOddCount;
            if (l == 0)
                rangeOddCount = prefOddCnt[r];
            else
                rangeOddCount = prefOddCnt[r] - prefOddCnt[l - 1];
            int m = l - r + 1;
            if (!isKEven) {
                if ((m - rangeOddCount) % 2 != 0 && totalOdd ||
                    (m - rangeOddCount) % 2 == 0 && !totalOdd) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }
            } else {
                if (rangeOddCount % 2 != 0 && !totalOdd ||
                    rangeOddCount % 2 == 0 && totalOdd) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
