#include <bits/stdc++.h>
using namespace std;

int countSetBits(long long n) {
    int c = 0;
    while (n > 0) {
        n &= (n - 1);
        c++;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long s, m;
        cin >> s >> m;
        int mSetBits = countSetBits(m);
        cout << "numSetBits: " << mSetBits << "\n";
        long long curr = ((1 << mSetBits) - 1);
        cout << "curr: " << curr << "\n";

        long long res = 0;

        while (curr > 0 && s > curr) {
            long long sub = 0;
            int j = mSetBits - 1;
            cout << "j: " << j << "\n";
            for (int i = 63; i >= 0; i--) {
                if (((1LL << i) & m) > 0) {
                    if ((1LL << j) & curr)
                        sub += ((1LL << i) & m);
                    j--;
                }
            }
            cout << "sub: " << sub << "\n";
            long long p = s / sub;
            res += p;
            s -= p * m;
            curr--;
            cout << "s: " << s << "\n";
        }

        // while (1 << mSetBits -)
        //     long long res = 0;
        // long long = for (int i = 0; i >= 0; i--) {
        //     if ((m & (1LL << i)) > 0) {
        //         long long p = s / m;
        //         res += s / m;
        //         s -= p * m;
        //         m ^= (1LL << i);
        //     }
        // }
        if (s > 0)
            cout << "-1\n";
        else
            cout << res << "\n";
    }
    return 0;
}
