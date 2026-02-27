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
        int rem = n;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        vector<bool> exists(n, true);
        long long cost = 0;
        int l = 0, c = 1, r = 2 % n;
        while (rem > 1) {
            while (nums[c] > nums[l]) {
                r = c;
                c = l;
                l = (l - 1 + n) % n;
                while (!exists[l]) {
                    l = (l - 1 + n) % n;
                }
            }
            while (nums[c] > nums[r]) {
                l = c;
                c = r;
                r = (r + 1 + n) % n;
                while (!exists[r]) {
                    r = (r + 1 + n) % n;
                }
            }
            exists[c] = false;
            rem--;
            if (nums[l] <= nums[r]) {
                cost += nums[l];
                c = l;
                l = (l - 1 + n) % n;
                while (rem > 1 && !exists[l]) {
                    l = (l - 1 + n) % n;
                }
            } else {
                cost += nums[r];
                c = r;
                r = (r + 1 + n) % n;
                while (rem > 1 && !exists[r]) {
                    r = (r + 1 + n) % n;
                }
            }
            // cout << cost << " ";
        }
        cout << cost << "\n";
    }
    return 0;
}
