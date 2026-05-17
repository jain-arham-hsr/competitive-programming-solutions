#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;
    vector<bool> exists(n);

    for (int i = 0; i < n; i++) {
        if (nums[i] < n)
            exists[nums[i]] = true;
    }
    int mex = 0;
    for (int i = 0; i < n; i++) {
        if (exists[i] || k > 0) {
            mex++;
            if (!exists[i])
                k--;
        } else {
            break;
        }
    }
    cout << mex;
    return 0;
}
