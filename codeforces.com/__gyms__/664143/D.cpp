#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> nums(n + 1);
    for (auto &x : nums)
        cin >> x;

    vector<long long> prefixSum(n + 1);
    partial_sum(nums.begin(), nums.end(), prefixSum.begin());

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        if (l == 0)
            sum = prefixSum[r - 1];
        else
            sum = prefixSum[r - 1] - prefixSum[l - 1];
        cout << fixed << setprecision(10)
             << sum / static_cast<long double>(nums[r]) << "\n";
    }

    return 0;
}
