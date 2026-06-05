#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, b, g;
        cin >> r >> b >> g;
        int bundles = min(min(r, b), g);
        r -= bundles;
        b -= bundles;
        g -= bundles;
        cout << bundles * 10 + (r + b + g) * 3 << "\n";
    }
}
