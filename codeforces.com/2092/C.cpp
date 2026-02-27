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
        int cntOdd = 0;
        int maxNum = nums[0];
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, nums[i]);
            sum += nums[i];
            if (nums[i] % 2 != 0)
                cntOdd++;
        }
        if (cntOdd == 0 || cntOdd == n) {
            cout << maxNum << "\n";
            continue;
        }
        cout << (sum - cntOdd + 1) << "\n";
    }
    return 0;
}
