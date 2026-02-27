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

        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        if (freq.size() == 1) {
            cout << "YES\n";
            continue;
        } else if (freq.size() == 2) {
            bool ok = true;
            for (auto it : freq) {
                if (it.second != n / 2 && it.second != (n + 1) / 2) {
                    ok = false;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
