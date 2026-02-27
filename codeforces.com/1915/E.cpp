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
        vector<long long> nums(n);
        for (auto &x : nums)
            cin >> x;
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                prefSum[i] = prefSum[i - 1] + nums[i];
            } else {
                prefSum[i] = prefSum[i - 1] - nums[i];
            }
        }
        bool ok = false;
        map<long long, bool> exists;
        for (int i = 0; i < n; i++) {
            if (exists[prefSum[i]] || prefSum[i] == 0) {
                ok = true;
                break;
            }
            exists[prefSum[i]] = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
