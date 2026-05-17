#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k, m;
        cin >> n >> k >> m;

        string s;
        cin >> s;

        vector<int> breaks;
        breaks.reserve(n);

        vector<bool> exists(k);
        int diff = k;

        for (int i = 0; i < m; i++) {
            if (!exists[s[i] - 'a']) {
                exists[s[i] - 'a'] = true;
                diff--;
            }
            if (diff == 0) {
                diff = k;
                breaks.push_back(i);
                fill(exists.begin(), exists.end(), false);
            }
        }

        if (breaks.size() >= n) {
            cout << "YES\n";
            continue;
        }

        string t(n, 'a');
        for (int i = 0; i < breaks.size(); i++) {
            t[i] = s[breaks[i]];
        }

        for (int i = 0; i < k; i++) {
            if (!exists[i]) {
                t[breaks.size()] = 'a' + i;
                break;
            }
        }
        cout << "NO\n";
        cout << t << "\n";
    }
    return 0;
}
