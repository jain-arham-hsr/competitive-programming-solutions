#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int maxA = INT_MIN, maxB = INT_MIN;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a > maxA) {
            maxA = a;
            if (b > maxB) {
                maxB = b;
            }
        }
    }

    cout << maxB;

    return 0;
}
