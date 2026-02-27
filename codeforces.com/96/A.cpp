#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int consecCount = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1])
            consecCount = 1;
        else {
            consecCount++;
        }
        if (consecCount == 7) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
