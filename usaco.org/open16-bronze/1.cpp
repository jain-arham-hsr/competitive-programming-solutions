#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> diamonds(n);
    for (auto &x : diamonds)
        cin >> x;

    sort(diamonds.begin(), diamonds.end());

    int r = 0;
    int maxNum = 0;
    for (int l = 0; l < n; l++) {
        while (r + 1 < n && diamonds[l] >= diamonds[r + 1] - k)
            r++;
        maxNum = max(maxNum, r - l + 1);
    }

    cout << maxNum;

    return 0;
}
