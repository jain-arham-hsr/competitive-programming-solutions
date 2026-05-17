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
        unordered_map<int, int> freq;
        for (int i = 0; i < 2 * n; i++) {
            int num;
            cin >> num;
            freq[num]++;
        }
        int res = 0;
        bool flag = false;
        for (auto it : freq) {
            if (it.second % 4 == 0) {
                if (flag)
                    res += 4;
                flag = !flag;
            }
        }
        for (auto it : freq) {
            if (it.second % 4 == 0)
                continue;
            if (it.second % 2 == 0)
                res += 2;
            else {
                if (flag == true) {
                    res += 2;
                    flag = false;
                }
                res += 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
