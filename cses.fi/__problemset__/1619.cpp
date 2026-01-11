#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> c;
    c.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        c.push_back({a, 1});
        c.push_back({b, -1});
    }

    sort(c.begin(), c.end());

    int currCount = 0;
    int maxCount = currCount;

    for (int i = 0; i < 2 * n; i++) {
        currCount += c[i].second;
        maxCount = max(maxCount, currCount);
    }

    cout << maxCount;

    return 0;
}
