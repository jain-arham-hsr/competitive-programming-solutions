#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int wcount = 0;
        for (int i = 0; i < k; i++) {
            wcount += s[i] == 'W';
        }
        int minWCount = wcount;
        for (int i = k; i < n; i++) {
            wcount += s[i] == 'W';
            wcount -= s[i - k] == 'W';
            minWCount = min(wcount, minWCount);
        }
        cout << minWCount << "\n";
    }
    return 0;
}
