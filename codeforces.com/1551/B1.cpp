#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        unordered_map<char, int> charCount;

        for (int i = 0; i < s.size(); i++) {
            charCount[s[i]]++;
        }

        bool isUnpaired = false;
        int numPaintedRed = 0;

        for (auto it : charCount) {
            if (it.second > 1) {
                numPaintedRed++;
            } else if (!isUnpaired) {
                numPaintedRed++;
                isUnpaired = !isUnpaired;
            } else {
                isUnpaired = !isUnpaired;
            }
        }

        cout << numPaintedRed - isUnpaired << "\n";
    }
    return 0;
}
