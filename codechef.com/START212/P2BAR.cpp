#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string transmission;
        cin >> n;
        cin >> transmission;
        bool flag = false;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (transmission[i] == '0')
                flag = true;
            if (!flag)
                continue;
            sum += transmission[i] - '0';
        }
        cout << sum << "\n";
    }
    return 0;
}
