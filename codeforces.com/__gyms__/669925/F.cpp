#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;
    sort(nums.begin(), nums.end());

    while (T--) {
        int x, y;
        cin >> x >> y;
        auto st = lower_bound(nums.begin(), nums.end(), x);
        auto ls = upper_bound(nums.begin(), nums.end(), y);
        cout << max(0, (int)distance(st, ls)) << "\n";
    }
    return 0;
}
