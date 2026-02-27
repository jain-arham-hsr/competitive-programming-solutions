#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> s;
    for (int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        s[num]++;
    }

    int res = 0;
    for (auto x : s) {
        res += x.second - 1;
    }

    cout << res << "\n";

    return 0;
}
