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
        vector<int> a(n);
        vector<int> freq(n + 1);
        for (auto x : a) {
            cin >> x;
            freq[x]++;
        }
        vector<int> cf(n + 1);
        partial_sum(freq.begin(), freq.end(), cf.begin());
        int l = -1, r = n + 1;
        bool ok = false;
        while (l < r - 1) {
            int mid = l + (r - l) / 2;
            if (n - cf[mid] == mid) {
                cout << mid << "\n";
                ok = true;
                break;
            } else if (n - cf[mid] < mid) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (!ok)
            cout << "-1\n";
    }
    return 0;
}
