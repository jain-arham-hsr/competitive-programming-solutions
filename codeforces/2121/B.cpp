#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n;
        cin >> s;

        vector<int> charFreq(26);
        charFreq[s[0] - 'a']++;
        charFreq[s[n - 1] - 'a']++;
        bool ok = false;
        for (int i = 1; i < n - 1; i++) {
            if (charFreq[s[i] - 'a'] > 0) {
                ok = true;
                break;
            }
            charFreq[s[i] - 'a']++;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
