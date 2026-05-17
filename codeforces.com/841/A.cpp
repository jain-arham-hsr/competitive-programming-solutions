#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    unordered_map<char, int> charCount;

    for (char &x : s)
        charCount[x]++;

    for (auto it : charCount) {
        if (it.second > k) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
