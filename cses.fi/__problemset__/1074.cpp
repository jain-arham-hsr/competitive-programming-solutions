#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;

    sort(nums.begin(), nums.end());

    int l = nums[n / 2];

    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(nums[i] - l);
    }

    cout << cost << "\n";

    return 0;
}
