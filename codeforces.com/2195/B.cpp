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
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (((i + 1) % nums[i] == 0 || nums[i] % (i + 1) == 0) &&
                log2(nums[i] / (i + 1)) == floor(log2(nums[i] / (i + 1)))) {
            } else {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
