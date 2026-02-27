#include <bits/stdc++.h>
using namespace std;

bool isPossible(string &s, int start, int aCount) {
    int n = s.size();
    if (start >= n)
        return true;
    for (int i = start; i < n; i++) {
        char curr = s[i];
        if (curr == '?') {
            int p = i;
            int quesCount = 0;
            while (p < n && s[p] == '?') {
                quesCount++;
                p++;
            }
            if (quesCount % 2 == 1) {
                if (aCount == 0 || aCount == 2) {
                    return isPossible(s, i + quesCount, 1);
                } else {
                    return (isPossible(s, i + quesCount, 0) ||
                            isPossible(s, i + quesCount, 2));
                }
            } else {
                if (aCount == 0 || aCount == 2) {
                    return (isPossible(s, i + quesCount, 0) ||
                            isPossible(s, i + quesCount, 2));
                } else {
                    return isPossible(s, i + quesCount, 1);
                }
            }
        }
        if (aCount == 0) {
            if (curr == 'a') {
                return false;
            } else {
                aCount = 1;
            }
        } else if (aCount == 2) {
            if (curr == 'a') {
                aCount = 1;
            } else {
                return false;
            }
        } else {
            if (curr == 'a') {
                aCount = 0;
            } else {
                aCount = 2;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int initACount = n % 2 == 1 ? 2 : 1;
        bool ok = isPossible(s, 0, initACount);
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
