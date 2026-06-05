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
        int res = 0;
        int currCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                currCount--;
            else
                currCount++;
            if (currCount >= 0)
                res++;
        }
        cout << res << "\n";
    }
    return 0;
}
