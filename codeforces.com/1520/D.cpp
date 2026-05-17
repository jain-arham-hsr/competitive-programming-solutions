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
        unordered_map<int, int> cnt;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += cnt[nums[i] - i];
            cnt[nums[i] - i]++;
        }
        cout << res << "\n";
    }
    return 0;
}
