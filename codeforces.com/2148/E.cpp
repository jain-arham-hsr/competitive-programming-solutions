#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        bool isPossible = true;
        for (auto it : cnt) {
            if (it.second % k != 0) {
                isPossible = false;
                break;
            }
        }
        if (!isPossible) {
            cout << "0\n";
            continue;
        }
        int reqValid = 0;
        for (auto it : cnt) {
            cnt[it.first] = it.second / k;
            reqValid++;
        }
        long long res = 0;
        int currValid = reqValid;
        unordered_map<int, int> currCnt;
        int l = 0;
        for (int r = 0; r < n; r++) {
            currCnt[nums[r]]++;
            if (currCnt[nums[r]] == cnt[nums[r]] + 1) {
                currValid--;
            }
            while (l < n && currValid != reqValid) {
                currCnt[nums[l]]--;
                if (currCnt[nums[l]] == cnt[nums[l]])
                    currValid++;
                l++;
            }
            if (currValid == reqValid) {
                res += r - l + 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
