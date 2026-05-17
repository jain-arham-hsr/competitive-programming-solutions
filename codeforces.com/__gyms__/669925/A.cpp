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
        int minDigit = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            minDigit = min(minDigit, s[i] - '0');
        }
        cout << minDigit << "\n";
    }
    return 0;
}
