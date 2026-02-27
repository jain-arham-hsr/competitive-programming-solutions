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
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int prevNum = a[i - 1];
            int prevComp = 7 - prevNum;
            if (a[i] == prevNum || a[i] == prevComp) {
                for (int j = 1; j <= 6; j++) {
                    if (i != n - 1 && (a[i + 1] == j || 7 - a[i + 1] == j))
                        continue;
                    if (j == prevNum || j == prevComp)
                        continue;
                    a[i] = j;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
