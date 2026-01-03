#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int res = 0;
    while (n--) {
        bool a, b, c;
        cin >> a >> b >> c;
        int p = a + b + c;
        if (p >= 2)
            res++;
    }
    cout << res;
    return 0;
}
