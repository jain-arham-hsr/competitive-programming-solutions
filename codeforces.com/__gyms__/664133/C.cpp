#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    bool lastEqual = s[0] == t[0];
    int res = 0;
    for (int i = 1; i< n; i++){
        if ((s[i] == t[i]) != lastEqual) {
            res++;
            lastEqual = s[i] == t[i];
        }
    }
    if (!lastEqual) res++;
    cout << res;
    return 0;
}
