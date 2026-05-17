#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<char, char> alpha;
    for (int i = 0; i < 26; i++) {
        char from, to;
        cin >> from >> to;
        alpha[from] = to;
    }

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] = alpha[s[i]];
    }

    cout << s;

    return 0;
}
