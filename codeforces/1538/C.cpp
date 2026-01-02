#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int lowerVal = a - nums[i];
            int upperVal = b - nums[i];
            auto lowerIt =
                lower_bound(nums.begin() + i + 1, nums.end(), lowerVal);
            auto upperIt =
                upper_bound(nums.begin() + i + 1, nums.end(), upperVal);
            res += distance(lowerIt, upperIt);
        }
        cout << res << "\n";
    }
    return 0;
}
