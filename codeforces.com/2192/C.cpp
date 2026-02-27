#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, h, k;
        cin >> n >> h >> k;
        vector<int> mag(n);
        for (auto &x : mag)
            cin >> x;
        long long sum = accumulate(mag.begin(), mag.end(), 0LL);
        long long res = (h / sum) * (n + k);
        h %= sum;
        if (h == 0) {
            cout << res << "\n";
            continue;
        }
        int maxNum = 0;
        int tempH = h;
        int x = n;
        for (int i = 0; i < n; i++) {
            if (tempH > 0)
                tempH -= mag[i];
            else {
                x = min(x, i);
                maxNum = max(maxNum, mag[i]);
            }
        }
        cout << "a: " << h << "\n";
        mag[x - 1] += tempH;
        int maxRem = 0;
        for (int i = 0; i < x; i++) {
            int p = h - mag[i];
            int rem = 0;
            while (x - rem - 1 >= 0 && mag[x - rem - 1] > p) {
                p -= mag[x - rem - 1];
                rem++;
            }
            maxRem = max(maxRem, rem);
        }
        res += x - maxRem;
        cout << res << "\n";
    }
    return 0;
}
