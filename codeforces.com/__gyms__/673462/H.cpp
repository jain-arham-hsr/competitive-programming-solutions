#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> tasks(n);

    long long res = 0;

    for (auto &x : tasks) {
        int d;
        cin >> x >> d;
        res += d;
    }

    sort(tasks.begin(), tasks.end());
    vector<long long> prefSum(n);
    partial_sum(tasks.begin(), tasks.end(), prefSum.begin());

    res -= accumulate(prefSum.begin(), prefSum.end(), 0LL);

    cout << res;

    return 0;
}
