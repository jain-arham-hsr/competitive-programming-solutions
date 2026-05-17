#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        vector<int> prefSum(n);
        sort(nums.begin(), nums.end());
        partial_sum(nums.rbegin(), nums.rend(), prefSum.begin());
        for (int i = 0; i < q; i++) {
            int p;
            cin >> p;
            auto it = lower_bound(prefSum.begin(), prefSum.end(), p);
            if (it == prefSum.end())
                cout << "-1\n";
            else
                cout << distance(prefSum.begin(), it) + 1 << "\n";
        }
    }
    return 0;
}
