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
        int i = 0;
        for (; i < n; i++) {
            if (nums[i] != n - i) {
                reverse(nums.begin() + i,
                        find(nums.begin(), nums.end(), n - i) + 1);
                break;
            } else {
                cout << nums[i] << " ";
            }
        }
        for (; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
