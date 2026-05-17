#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> strs(n);
    for (auto &x : strs)
        cin >> x;

    unordered_map<string, int> schemeFreq;

    for (int i = 0; i < n; i++) {
        string t = "";
        char currChar = 'A';
        vector<char> schema(26);
        for (char ch : strs[i]) {
            if (!schema[ch - 'a']) {
                schema[ch - 'a'] = currChar;
                currChar++;
            }
            t.push_back(schema[ch - 'a']);
        }
        schemeFreq[t]++;
    }
    long long res = 0;

    for (auto &x : schemeFreq) {
        res += ((long long)x.second * (x.second - 1)) / 2;
    }

    cout << res << "\n";

    return 0;
}
