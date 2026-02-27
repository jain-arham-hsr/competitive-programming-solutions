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
        string s;
        cin >> s;
        int blocks = 1;
        int maxBlockSize = 1;
        int blockSize = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                blocks++;
                maxBlockSize = max(blockSize, maxBlockSize);
                blockSize = 1;
            } else {
                blockSize++;
            }
        }
        maxBlockSize = max(blockSize, maxBlockSize);
        if (s[0] != s[n - 1] && maxBlockSize > 1)
            blocks++;
        cout << blocks << "\n";
    }
    return 0;
}
