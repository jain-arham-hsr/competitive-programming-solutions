#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> currents(n);
    for (auto &x : currents)
        cin >> x;

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        long long addend = (i + 1) * currents[i];
        if (i % 2 != 0)
            addend *= -1;
        sum += addend;
    }

    cout << sum;

    return 0;
}
