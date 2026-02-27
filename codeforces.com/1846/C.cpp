#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<pair<pair<int, long long>, int>> scoreTable(n);
        for (int i = 0; i < n; i++) {
            vector<int> probs(m);
            for (auto &x : probs)
                cin >> x;
            sort(probs.begin(), probs.end());
            int solved = 0;
            int timeElapsed = 0;
            long long penalty = 0;
            for (int j = 0; j < m; j++) {
                if (timeElapsed + probs[j] <= h) {
                    timeElapsed += probs[j];
                    penalty += timeElapsed;
                    solved++;
                } else
                    break;
            }
            scoreTable[i] = {{m - solved, penalty}, i};
        }
        sort(scoreTable.begin(), scoreTable.end());
        for (int i = 0; i < n; i++) {
            if (scoreTable[i].second == 0)
                cout << i + 1 << "\n";
        }
    }
    return 0;
}
