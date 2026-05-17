#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        sort(nums.begin(), nums.end());
        vector<int> res(n);
        int a = 0;
        int b = n - 1;
        long long currSum = 0;
        long long maxBonus = 0;
        for (int i = 0; i < n; i++) {
            if (currSum + nums[b] >= x) {
                currSum = (currSum + nums[b]) % x;
                res[i] = nums[b];
                maxBonus += nums[b];
                b--;
            } else {
                currSum += nums[a];
                res[i] = nums[a];
                a++;
            }
        }
        cout << maxBonus << "\n";
        for (auto &x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
