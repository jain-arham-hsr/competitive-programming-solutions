#include <bits/stdc++.h>
using namespace std;

long long func(long long &extraSum, long long &totalSum, long long i) {
    long long addVal = i * (i + 1) / 2 - extraSum;
    long long subVal = totalSum - i * (i + 1) / 2;
    long long val = abs(addVal - subVal);
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long n, k;
        cin >> n >> k;
        long long totalSum = (k + n) * (k + n - 1) / 2;
        long long extraSum = k * (k - 1) / 2;
        int left = k - 1, right = k + n;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            long long midSlope = func(extraSum, totalSum, mid + 1) -
                                 func(extraSum, totalSum, mid);
            if (midSlope > 0) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << func(extraSum, totalSum, right) << "\n";
    }
    return 0;
}
