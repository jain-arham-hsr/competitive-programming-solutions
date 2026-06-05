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
        long long minSum = nums[0];
        for (int i = 1; i < n; i++) {
            minSum += 2 * nums[i];
        }
        long long maxSum = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxSum = nums[i] + 2 * maxSum;
        }
        cout << minSum << " " << maxSum << "\n";
    }
    return 0;
}
