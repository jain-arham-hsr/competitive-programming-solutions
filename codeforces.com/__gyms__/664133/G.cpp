#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (auto &x : nums)
        cin >> x;
    long long currSum = nums[0];
    int l = 1;
    while (l < n && k - currSum >= nums[l]) {
        currSum += nums[l];
        l++;
    }
    int r = l;
    // cout << "l: " << l << "\n";
    if (r != n) {
        if (r % 2 == 0) {
            r -= 2;
        }
        r /= 2;
    }
    // cout << "r: " << r << "\n";
    for (int i = l; i < n; i++) {
        // cout << currSum << "\n";
        if (i - 2 * r - 1 >= 0)
            currSum -= nums[i - 2 * r - 1];
        while (r >= 0 && k - currSum < nums[i]) {
            r--;
            cout << r << "\n";
            if (i - 2 * r - 1 >= 0)
                currSum -= nums[i - 2 * r - 1];
        }
        currSum += nums[i];
    }
    cout << r;
    return 0;
}
