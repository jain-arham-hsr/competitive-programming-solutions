#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            res++;
    }

    cout << res;

    return 0;
}
