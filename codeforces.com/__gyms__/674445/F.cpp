#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p, q;
    cin >> n >> p >> q;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    long long res = 0;

    while (pq.top() - (q * res) > 0) {
        int a = pq.top();
        pq.pop();
        while (a >= pq.top() && a - (q * res) > 0) {
            a -= p - q;
            res++;
        }

        pq.push(a);
    }

    cout << res;

    return 0;
}
