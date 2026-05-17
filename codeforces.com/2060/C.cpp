#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int numOfPairs = 0;
        unordered_map<int, int> isUnpaired;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (isUnpaired[k - num]) {
                isUnpaired[k - num]--;
                numOfPairs++;
            } else {
                isUnpaired[num]++;
            }
        }
        cout << numOfPairs << "\n";
    }
    return 0;
}
