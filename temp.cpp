#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> res1(n);
    res1[0] = a[0];
    int mx = -1e5;
    for (int i = 1; i < n - 1; i++) {
        int sum = 0;

        for (int j = 0; j < i; j++) {
            sum += res1[j];
        }
        res1[i] = max(a[i] - sum, a[i] + sum);
        res1[i] = max(a[i], res1[i]);
    }
    vector<int> res2(n);
    res2[0] = a[0];
    for (int i = 1; i < n - 1; i++) {
        int sum = 0;

        for (int j = 0; j < i; j++) {
            sum += res2[j];
        }
        res2[i] = min(a[i] - sum, a[i] + sum);
        res2[i] = min(a[i], res2[i]);
    }

    int s1 = 0;
    for (int i = 0; i < n - 1; i++) {
        s1 += res1[i];
    }
    int s2 = 0;
    for (int i = 0; i < n - 1; i++) {
        s2 += res2[i];
    }
    res1[n - 1] = a[n - 1] + abs(s1);
    res2[n - 1] = a[n - 1] + abs(s2);
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());
    cout << max(res1[n - 1], res2[n - 1]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TESTCASES = 1;
    cin >> TESTCASES;
    while (TESTCASES--) {
        solve();
    }
}
