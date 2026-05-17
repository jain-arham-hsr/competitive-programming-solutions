#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(nums.begin(), nums.end(), x);
        cout << distance(it, nums.end()) << "\n";
    }
    return 0;
}
