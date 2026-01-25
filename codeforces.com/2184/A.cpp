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
        int numTeams = n / 2;
        int rem = n % 2;
        if (numTeams % 2 == 0) {
            cout << rem;
        } else {
            if (numTeams == 1)
                cout << (2 + rem);
            else
                cout << rem;
        }
        cout << "\n";
    }
    return 0;
}
