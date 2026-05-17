#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    long double log_2 = log2(n);
    if (floor(log_2) == log_2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
