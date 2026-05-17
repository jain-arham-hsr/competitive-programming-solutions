#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> messages(n);

    for (auto &x : messages)
        cin >> x;

    unordered_map<string, bool> isIncluded;

    for (int i = n - 1; i >= 0; i--) {
        if (!isIncluded[messages[i]]) {
            cout << messages[i] << "\n";
            isIncluded[messages[i]] = true;
        }
    }

    return 0;
}
