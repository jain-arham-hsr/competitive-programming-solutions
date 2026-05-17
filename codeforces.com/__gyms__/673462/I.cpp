#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, w;
        cin >> n >> w;
        cout << n - (n / w) << "\n";
    }
    return 0;
}
