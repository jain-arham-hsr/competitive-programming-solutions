#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

ostream &operator<<(ostream &os, const string &s) {
    for (char c : s)
        os << c;
    return os;
}

template <typename T, typename = typename T::iterator>
ostream &operator<<(ostream &os, const T &c) {
    os << "{";
    bool f = true;
    for (auto &x : c)
        os << (f ? f = false, "" : ", ") << x;
    return os << "}";
}

void debug_out() { cerr << "\n"; }
template <typename H, typename... T> void debug_out(H &&h, T &&...t) {
    cerr << h;
    if constexpr (sizeof...(t))
        cerr << ", ";
    debug_out(forward<T>(t)...);
}

#ifdef DEBUGGER
#define watch(...)                                                             \
    cerr << __func__ << ":" << __LINE__ << " | " << #__VA_ARGS__ << " = ",     \
        debug_out(__VA_ARGS__)
#else
#define watch(...) ((void)0)
#endif

// ==================================================================== //

ll MOD = 998244353;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> freq(105);
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            freq[num]++;
        }

        ll res = 0;
        ll prevWays = 1;

        for (int i = 0; i < n + 5; i++) {
            ll temp = res;
            if (i == 0)
                res += (power(2, freq[1], MOD) - 1 + MOD) % MOD;
            else
                res = (res +
                       ((prevWays % MOD) * power(2, freq[i + 1], MOD)) % MOD) %
                      MOD;
            watch(prevWays, res - temp);
            prevWays = ((prevWays % MOD) *
                        ((power(2, freq[i], MOD) - 1 + MOD) % MOD)) %
                       MOD;
        }

        cout << (res % MOD) << "\n";
    }
    return 0;
}
