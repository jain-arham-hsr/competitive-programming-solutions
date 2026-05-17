#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<string, bool> hasOccurred;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (!hasOccurred[name])
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";

        hasOccurred[name] = true;
    }
    return 0;
}
