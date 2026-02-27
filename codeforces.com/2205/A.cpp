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
        int ind = distance(nums.begin(), find(nums.begin(), nums.end(), n));
        swap(nums[0], nums[ind]);
        for (auto &x : nums)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
