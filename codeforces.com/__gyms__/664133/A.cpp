#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    string pattern = "nlogn";
    bool exists = false;
    for (int i = 0; i < n - 4; i++) {
        bool isMatch = true;
        for (int j = 0; j <= 4; j++) {
            if (s[i + j] != pattern[j]) {
                isMatch = false;
                break;
            }
        }
        if (isMatch) {
            exists = true;
            break;
        }
    }
    cout << ((exists) ? "Selected" : "Not Selected");
    return 0;
}
