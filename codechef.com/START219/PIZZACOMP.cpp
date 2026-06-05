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
        string out;
        if (100.0 / a > 225.0 / b) {
            out = "Small";
        } else if (100.0 / a < 225.0 / b) {
            out = "Large";
        } else {
            out = "Equal";
        }
        cout << out << "\n";
    }
    return 0;
}
