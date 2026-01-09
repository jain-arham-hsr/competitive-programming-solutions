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
        for (int i = 0; i < n; i++) {
            if (i < k)
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
