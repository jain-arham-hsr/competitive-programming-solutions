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

    sort(nums.begin(), nums.end());

    vector<int> factors;
    map<int, bool> factorsUsed;
    map<int, vector<int>> countToNum;

    for (int i = 0; i < n; i++) {
        int currNum = nums[i];
        int factorCount = 0;
        for (int j = 1; j <= sqrt(currNum); j++) {
            if (currNum % j == 0) {
                if (currNum / j == j) {
                    factorCount++;
                } else {
                    factorCount += 2;
                }
            }
        }
        if (!factorsUsed[factorCount])
            factors.push_back(factorCount);
        factorsUsed[factorCount] = true;
        countToNum[factorCount].push_back(currNum);
    }
    sort(factors.begin(), factors.end());
    for (auto &x : factors) {
        for (auto &y : countToNum[x])
            cout << y << " ";
    }

    return 0;
}
