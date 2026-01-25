#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;
        vector<long long> b(n);
        for (auto &x : b)
            cin >> x;

        sort(a.begin(), a.end());
        int j = -1;
        long long req = 0;
        long long maxScore = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            while (i > 0 && a[i] == a[i - 1])
                i--;
            int sw = n - i;
            while (j < n - 1 && req + b[j + 1] <= sw) {
                j++;
                req += b[j];
            }
            maxScore = max(maxScore, a[i] * (j + 1));
        }
        cout << maxScore << "\n";
    }
    return 0;
}
