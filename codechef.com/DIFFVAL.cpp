#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        unordered_map<int, int> columnSum;
        int currentCol = 0;

        int tempN = n;
        while (tempN > 0) {
            if (tempN >= k) {
                columnSum[currentCol] += k;
            } else {
                columnSum[currentCol] += tempN;
            }
            tempN -= k;
            currentCol = !currentCol;
        }

        int oddColumns = columnSum[0];
        int evenColumns = columnSum[1];
        int a = min(oddColumns, evenColumns);
        int d = abs(oddColumns - evenColumns);

        unordered_map<int, int> count;

        for (int i = 0; i < n; i++) {
            count[s[i] - '0']++;
        }

        if (count[0] < a || count[1] < a) {
            cout << "NO" << "\n";
            continue;
        } else {
            count[0] -= a;
            count[1] -= a;
            if (count[0] + count[1] == d) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
