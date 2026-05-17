#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        char c;
        cin >> n;
        cin >> c;
        string s;
        cin >> s;
        s = s + s;
        int maxLength = 0;
        int firstC = 0;
        bool isCounting = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c && !isCounting) {
                firstC = i;
                isCounting = true;
            }
            if (s[i] == 'g' && isCounting) {
                maxLength = max(i - firstC, maxLength);
                isCounting = false;
            }
        }
        cout << maxLength << "\n";
    }
    return 0;
}
