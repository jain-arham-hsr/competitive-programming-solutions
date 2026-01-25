#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long w, h, n;
    cin >> w >> h >> n;

    long long side = 0;
    long long rowsFilled = 0;
    long long columnsFilled = 0;

    for (int i = 0; i < n; i++) {
        if (max(rowsFilled + h, side) < max(columnsFilled + w, side)) {
            rowsFilled += h;
            columnsFilled = 0;
            side = max(rowsFilled, side);
        } else {
            columnsFilled += w;
            rowsFilled = 0;
            side = max(columnsFilled, side);
        }
    }
    cout << side;

    return 0;
}
