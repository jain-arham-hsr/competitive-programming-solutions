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
        string s;
        cin >> s;
        vector<int> onePos;
        vector<int> zeroPos;
        onePos.reserve(n);
        zeroPos.reserve(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                onePos.push_back(i + 1);
            } else {
                zeroPos.push_back(i + 1);
            }
        }
        if (onePos.size() % 2 == 1 && zeroPos.size() % 2 == 0) {
            cout << -1 << "\n";
        } else if (zeroPos.size() % 2 == 1) {
            cout << zeroPos.size() << "\n";
            for (auto &x : zeroPos)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << onePos.size() << "\n";
            for (auto &x : onePos)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}   
