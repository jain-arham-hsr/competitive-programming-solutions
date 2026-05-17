#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<string, int> names;

    for (int i = 0; i < n; i++) {
        string userInp;
        cin >> userInp;

        if (names[userInp] != 0) {
            cout << userInp << names[userInp] << "\n";
        } else {
            cout << "OK" << "\n";
        }

        names[userInp]++;
    }

    return 0;
}
