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
        vector<int> seating(n);
        for (auto &x : seating)
            cin >> x;
        int totalDisturbed = 0;
        for (int i = 0; i < n; i++) {
            int leftCount = 0;
            for (int j = 0; j < i; j++) {
                if (seating[j] < seating[i])
                    leftCount++;
            }
            totalDisturbed += min(leftCount, seating[i] - 1 - leftCount);
        }
        cout << totalDisturbed << "\n";
    }
    return 0;
}
