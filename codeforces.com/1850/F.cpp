#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            freq[num]++;
        }
        vector<int> pos(n + 1);
        for (auto it : freq) {
            for (int j = it.first; j <= n; j += it.first) {
                pos[j] += it.second;
            }
        }
        int maxCnt = 0;
        for (int i = 0; i <= n; i++) {
            maxCnt = max(maxCnt, pos[i]);
        }
        cout << maxCnt << "\n";
    }
    return 0;
}
