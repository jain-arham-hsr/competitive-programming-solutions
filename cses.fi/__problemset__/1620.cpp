#include <bits/stdc++.h>
using namespace std;

long long numOfProducts(vector<int> &k, int &t, long long timeElapsed) {
    long long p = 0;
    for (auto &x : k) {
        long long add = timeElapsed / x;
        if (p >= t - add)
            return t;
        p += add;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    vector<int> k(n);
    for (auto &x : k)
        cin >> x;

    long long l = -1, r = 1e18 + 1;
    while (l < r - 1) {
        long long mid = l + (r - l) / 2;
        if (numOfProducts(k, t, mid) < t) {
            l = mid;
        } else
            r = mid;
    }
    cout << r;

    return 0;
}
