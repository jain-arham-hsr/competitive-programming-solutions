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
        unordered_map<int, int> freq;
        for (auto &x : nums) {
            cin >> x;
            freq[x]++;
        }
        int currentLength = 0;
        int maxLength = 0;
        int bestEndInd = -1;
        for (int i = 0; i < n; i++) {
            if (freq[nums[i]] == 1) {
                currentLength++;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    bestEndInd = i;
                }
            } else {
                currentLength = 0;
            }
        }
        if (maxLength == 0) {
            cout << "0\n";
        } else {
            int bestStartInd = bestEndInd - maxLength + 1;
            cout << bestStartInd + 1 << " " << bestEndInd + 1 << "\n";
        }
    }
    return 0;
}
