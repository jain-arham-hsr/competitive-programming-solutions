#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        h.insert(num);
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        auto t = h.upper_bound(q);
        if (t == h.begin()) {
            cout << -1 << "\n";
            continue;
        }
        t--;
        cout << (*t) << "\n";
        h.erase(t);
    }
    return 0;
}
