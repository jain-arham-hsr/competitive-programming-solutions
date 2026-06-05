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
        string binString;
        cin >> binString;
        int contChar = 1;
        int diff = 0;
        // bool oneExists = false;
        for (int i = 1; i < n; i++) {
            if (binString[i] == '1')
                // oneExists = true;
                if (binString[i] == binString[i - 1]) {
                    contChar++;
                } else {
                    if (binString[i - 1] == '0')
                        diff += contChar - 1;
                    else
                        diff -= contChar - 1;
                    contChar = 1;
                }
        }
        // cout << "contChar " << contChar << "\n";
        if (binString[n - 1] == '0')
            diff += contChar - 1;
        else
            diff -= contChar - 1;
        // cout << "diff: " << diff << "\n";
        int res = 0;
        if (diff <= 0) {
            cout << res;
        } else {
            // if (!oneExists) {
            //     diff--;
            //     res++;
            // }
            res += ceil(diff / 2.0);
            cout << res;
        }
        cout << "\n";
    }
    return 0;
}
