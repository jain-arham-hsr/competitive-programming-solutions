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
        vector<int> nums(2 * n);
        for (auto &x : nums)
            cin >> x;

        sort(nums.begin(), nums.end());

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(nums[i] - nums[2 * n - 1 - i]);
        }
        cout << sum << "\n";
    }
    return 0;
}
