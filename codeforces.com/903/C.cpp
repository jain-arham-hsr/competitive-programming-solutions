#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> sizeCounts;

    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        sizeCounts[size]++;
    }

    int maxCount = INT_MIN;

    for (auto it : sizeCounts)
        maxCount = max(it.second, maxCount);

    cout << maxCount;

    return 0;
}
