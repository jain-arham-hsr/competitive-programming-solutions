#include <bits/stdc++.h>
using namespace std;

long long sumOfDigits(long long n) {
    if (n == 0)
        return 0;
    return sumOfDigits(n / 10) + (n % 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> nums(n);
    vector<long long> twirls(n);
    for (auto &x : nums)
        cin >> x;
    for (int i = 0; i < n; i++) {
        twirls[i] = sumOfDigits(nums[i]);
    }
    int parityCount = 1;
    bool currParity = (twirls[0] % 2 == 0);

    for (int i = 1; i < n; i++) {
        if ((twirls[i] % 2 == 0) != (currParity)) {
            currParity = (twirls[i] % 2 == 0);
            parityCount++;
        }
    }

    cout << parityCount;

    return 0;
}
