#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, s;
    cin >> n >> s;

    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    vector<long long> prefSum(n + 1);
    prefSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefSum[i] = prefSum[i - 1] + a[i - 1];
    }

    unordered_map<long long, int> freq;

    long long res = 0;
    for (int i = 0; i <= n; i++) {
        res += freq[prefSum[i] - s];
        freq[prefSum[i]]++;
    }

    cout << res;

    return 0;
}
