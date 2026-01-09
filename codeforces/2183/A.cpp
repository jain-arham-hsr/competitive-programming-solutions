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
        if (nums[0] == 0 && nums[n - 1] == 0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    return 0;
}
