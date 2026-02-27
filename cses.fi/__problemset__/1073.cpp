#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> blocks(n);
    for (auto &x : blocks)
        cin >> x;

    vector<int> towers;

    for (int i = 0; i < n; i++) {
        auto it = upper_bound(towers.begin(), towers.end(), blocks[i]);
        if (it == towers.end()) {
            towers.push_back(blocks[i]);
        } else {
            *it = blocks[i];
        }
    }

    cout << towers.size();

    return 0;
}
