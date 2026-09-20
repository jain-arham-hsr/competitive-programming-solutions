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

struct Comb {
    long long MOD;
    vector<long long> fact, inv_fact;

    Comb(int maxn, long long mod) : MOD(mod), fact(maxn), inv_fact(maxn) {
        fact[0] = 1;
        for (int i = 1; i < maxn; i++)
            fact[i] = fact[i - 1] * i % MOD;
        inv_fact[maxn - 1] = power(fact[maxn - 1], MOD - 2);
        for (int i = maxn - 2; i >= 0; i--)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    long long nPr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * inv_fact[n - r] % MOD;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }

  private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        for (; exp > 0; exp >>= 1) {
            if (exp & 1)
                res = res * base % MOD;
            base = base * base % MOD;
        }
        return res;
    }
};

int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Comb comb(n + m, MOD);

    cout << comb.nCr(n + m - 1, n - 1);

    return 0;
}
