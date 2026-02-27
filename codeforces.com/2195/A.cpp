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
        bool onePresent = false;
        bool sixtySevenPresent = false;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num == 1)
                onePresent = true;
            else if (num == 67)
                sixtySevenPresent = true;
        }
        cout << ((sixtySevenPresent) ? "YES\n" : "NO\n");
    }
    return 0;
}
