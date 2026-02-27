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
        if (n % 2 == 0)
            cout << n << " ";
        else
            cout << n - 1 << " ";
        for (int i = 2; i < n; i += 2) {
            cout << i + 1 << " ";
            if (i != n - 1)
                cout << i << " ";
        }
        cout << 1 << "\n";
    }
    return 0;
}
