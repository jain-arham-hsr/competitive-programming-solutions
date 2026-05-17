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
        unordered_map<int, int> numCount;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            numCount[num]++;
        }
        int diversity = 0;
        for (auto it : numCount) {
            if (it.second > 0) {
                diversity++;
                if (it.second > 1) {
                    if (numCount[it.first + 1] == 0)
                        diversity++;
                    else
                        numCount[it.first + 1]++;
                }
            }
        }
        cout << diversity << "\n";
    }
    return 0;
}
