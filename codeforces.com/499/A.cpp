#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int res = 0;

    int curr = 1;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        res += (l - curr) % x;
        res += r + 1 - l;
        curr = r + 1;
    }

    cout << res;

    return 0;
}
