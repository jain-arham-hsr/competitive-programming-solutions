#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        int i = 0;
        while (n > 1) {
            n = (n + 1) / 2;
            i++;
        }
        cout << i << "\n";
    }
    return 0;
}
