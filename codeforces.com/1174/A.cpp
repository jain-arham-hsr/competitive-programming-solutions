#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(2 * n);
    for (auto &x : nums)
        cin >> x;
    sort(nums.begin(), nums.end());
    if (nums[0] == nums[2 * n - 1])
        cout << -1;
    else
        for (auto &x : nums)
            cout << x << " ";
    return 0;
}
