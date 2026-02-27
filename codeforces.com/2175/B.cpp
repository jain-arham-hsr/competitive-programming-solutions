#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 == r)
                b[i] = l - 1;
            else
                b[i] = i + 1;
        }
        cout << b[0] << " ";
        for (int i = 1; i < n; i++) {
            cout << (b[i] ^ b[i - 1]) << " ";
        }
        cout << "\n";
    }
    return 0;
}
