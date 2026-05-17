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
        string t = "";
        for (int i = 0; i < k; i++) {
            t += 'a' + i;
        }
        string s = "";
        for (int i = 0; i < n; i++) {
            s += t;
        }
        cout << s << "\n";
    }
    return 0;
}
