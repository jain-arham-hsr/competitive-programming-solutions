#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> rows(n);

    for (int i = 0; i < n; i++) {
        vector<int> nums(3);
        for (auto &x : nums)
            cin >> x;
        sort(nums.begin(), nums.end());
        rows[i] = nums;
    }

    int colAMax = rows[0][0];
    int colBMax = rows[0][1];

    for (auto &row : rows) {
        colAMax = max(colAMax, row[0]);
        colBMax = max(colBMax, row[1]);
    }

    vector<int> res;
    res.reserve(n);

    for (int i = 0; i < n; i++) {
        if (rows[i][1] > colAMax && rows[i][2] > colBMax) {
            res.push_back(i + 1);
        }
    }

    cout << res.size() << "\n";
    for (auto &x : res)
        cout << x << " ";

    return 0;
}
