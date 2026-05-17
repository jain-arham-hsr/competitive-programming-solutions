#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    vector<pair<int, string>> mice(m);
    for (auto &x : mice)
        cin >> x.first >> x.second;

    sort(mice.begin(), mice.end());

    int eq = 0;
    long long cost = 0;

    for (int i = 0; i < m; i++) {
        if (mice[i].second == "USB") {
            if (a > 0) {
                a--;
                eq++;
                cost += mice[i].first;
            } else if (c > 0) {
                c--;
                eq++;
                cost += mice[i].first;
            }
        } else {
            if (b > 0) {
                b--;
                eq++;
                cost += mice[i].first;
            } else if (c > 0) {
                c--;
                eq++;
                cost += mice[i].first;
            }
        }
    }
    cout << eq << " " << cost;

    return 0;
}
