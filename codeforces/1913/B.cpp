#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> count(2);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            count[s[i] - '0']++;
        }
        char toDel = count[0] > count[1] ? '0' : '1';
        int currOppCount = 0;
        int res = 0;
        int diff = abs(count[0] - count[1]);
        if (diff == 0) {
            cout << "0\n";
            continue;
        }
        for (int i = n - 1; i >= 0 && diff > 0; i--) {
            if (s[i] != toDel)
                currOppCount++;
            else {
                if (currOppCount <= 0) {
                    diff--;
                }
                currOppCount--;
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
