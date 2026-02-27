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
        cout << 1 << " ";
        for (int i = 0; i < n - 3; i++) {
            cout << i + 1 << " ";
        }
        cout << 1 << " " << 2 << "\n";
    }
    return 0;
}
