#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string name;
        int num;
        cin >> name >> num;
        freq[name]++;
    }

    long long res = tgamma(n + 1);

    for (auto it : freq) {
        res /= pow(2, it.second - 1);
    }

    cout << res;

    return 0;
}
