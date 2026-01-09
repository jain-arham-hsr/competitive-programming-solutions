#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (min(a, b) == 1 || a == 2 && b == 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
