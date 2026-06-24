#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;

    map<int, int> lastIndex;

    for (int i = 0; i < n; i++) {
        lastIndex[nums[i]] = i;
    }

    // for (auto &x : nums)
    //     cout << lastIndex[x] << " ";

    for (int i = 0; i < n; i++) {
        for (int j = i; j <= lastIndex[nums[i]]; j++) {
            cout << nums[i] << " ";
        }
        i = lastIndex[nums[i]];
    }

    return 0;
}
