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
        int k = count(nums.begin(), nums.end(), 0);
        if (n - k <= 1) {
            cout << 3 << "\n";
            cout << 3 << " " << n << "\n";
            cout << 1 << " " << 2 << "\n";
            cout << 1 << " " << 2 << "\n";
            continue;
        }
        k -= nums[n - 1] == 0 && nums[n - 2] == 0;
        cout << k + 1 << "\n";
        if (nums[n - 1] == 0 || nums[n - 2] == 0) {
            cout << n - 1 << " " << n << "\n";
        }
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i] == 0) {
                cout << i + 1 << " " << i + 2 << "\n";
            }
        }
        cout << 1 << " " << n - k << "\n";
    }
    return 0;
}
