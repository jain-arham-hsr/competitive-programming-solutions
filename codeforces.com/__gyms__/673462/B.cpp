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

    int s = nums[(n + 1) / 2 - 1];
    long long cost = 0;
    for (auto &x : nums) {
        cost += abs(s - x);
    }

    cout << cost;

    return 0;
}
