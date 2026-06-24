#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);

    for (auto &p : nums)
        cin >> p;

    map<int, int> originalNumsFreq;
    map<int, int> andNumsFreq;

    for (int i = 0; i < n; i++) {
        int originalNum = nums[i];
        if (originalNumsFreq[originalNum] > 0) {
            cout << 0;
            return 0;
        }
        originalNumsFreq[originalNum]++;
    }

    for (int i = 0; i < n; i++) {
        int originalNum = nums[i];
        int andNum = originalNum & x;
        if (originalNumsFreq[andNum] > 0) {
            if (andNum == originalNum && originalNumsFreq[andNum] > 1) {
                cout << 1;
                return 0;
            } else if (andNum != originalNum) {
                cout << 1;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int originalNum = nums[i];
        int andNum = originalNum & x;
        if (andNumsFreq[andNum] > 0) {
            cout << 2;
            return 0;
        }
        andNumsFreq[andNum]++;
    }

    cout << -1;

    return 0;
}
