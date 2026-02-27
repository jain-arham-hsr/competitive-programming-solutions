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

        int l = nums[0], r = nums[0];
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                r = nums[i];
                continue;
            } else if (nums[i] <= nums[i - 1] && nums[i] > l) {
                continue;
            } else {
                res++;
                l = nums[i];
                r = l;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
