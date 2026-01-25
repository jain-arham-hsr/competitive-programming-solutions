#include <bits/stdc++.h>
using namespace std;

int numMinutes(int x, int k, map<int, int> &memo) {
    if (x == k) {
        memo[x] = 0;
        return 0;
    } else if (x < k) {
        memo[x] = -1;
        return -1;
    }
    if (x % 2 == 0) {
        int half = numMinutes(x / 2, k, memo);
        if (half == -1)
            return -1;
        else
            return 1 + half;
    } else {
        int less, more;
        if (memo[x / 2] != 0) {
            less = memo[x / 2];
        } else {
            less = numMinutes(x / 2, k, memo);
        }
        if (memo[(x + 1) / 2] != 0) {
            more = memo[(x + 1) / 2];
        } else {
            more = numMinutes((x + 1) / 2, k, memo);
        }
        if (less == -1 && more == -1) {
            memo[x] = -1;
            return -1;
        } else if (less == -1) {
            memo[x] = 1 + more;
            return 1 + more;
        } else if (more == -1) {
            memo[x] = 1 + less;
            return 1 + less;
        } else {
            memo[x] = 1 + min(less, more);
            return 1 + min(less, more);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        map<int, int> memo;
        cout << numMinutes(n, k, memo) << "\n";
    }
    return 0;
}
