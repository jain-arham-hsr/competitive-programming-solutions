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
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        sort(nums.begin(), nums.end());
        vector<int> dst(n);
        for (int i = 1; i < n - 1; i++) {
            int dist = distance(lower_bound(nums.begin() + i, nums.end(),
                                            nums[i - 1] + nums[i]),
                                nums.end());
            dst[dist]++;
        }
        vector<int> dstSum(n);
        partial_sum(dst.begin() + 1, dst.end(), dstSum.begin() + 1);
        int res = 0;
        int j = 0;
        for (int i = 1; i < n; i++) {
            if (dst[i] > 0 && dstSum[i] - dstSum[j] > i - j) {
                res += i - j;
                j = i;
            }
        }
        res += dstSum[n - 1] - dstSum[j];
        cout << res << "\n";
    }
    return 0;
}
