#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    long long steps = 0;
    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;
            steps++;
        } else {
            n--;
            steps++;
        }
    }
    cout << steps;

    return 0;
}
