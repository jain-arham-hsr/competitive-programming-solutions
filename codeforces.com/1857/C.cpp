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
        int m = (n * (n - 1)) / 2;
        vector<int> b(m);
        for (auto &x : b)
            cin >> x;
        unordered_map<int, int> freq;
        for (int i = 0; i < m; i++)
            freq[b[i]]++;
        int numPairs = n - 1;
        vector<int> res;
        res.reserve(n);
        for (auto it : freq) {
            while (freq[it.first] > 0) {
                freq[it.first] -= numPairs;
                res.push_back(it.first);
                numPairs--;
            }
        }
        res.push_back(res[n - 2]);
        for (auto &x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
