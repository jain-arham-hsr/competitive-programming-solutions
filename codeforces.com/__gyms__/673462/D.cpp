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
        vector<int> nums(2 * n);
        for (auto &x : nums)
            cin >> x;
        sort(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 0; i < n; i++) {
            score += nums[2 * n - 1 - i] - nums[i];
        }
        cout << score << "\n";
    }
    return 0;
}
