#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;

ostream &operator<<(ostream &os, i128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9)
        os << (i128)(x / 10);
    return os << (int)(x % 10);
}

ostream &operator<<(ostream &os, u128 x) {
    if (x > 9)
        os << (u128)(x / 10);
    return os << (int)(x % 10);
}

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

int MOD = 1e9 + 7;

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

template <int MOD> struct Mint {
    int v;

    Mint() : v(0) {}
    Mint(long long x) {
        x %= MOD;
        v = x < 0 ? x + MOD : x;
    }

    Mint &operator+=(const Mint &o) {
        if ((v += o.v) >= MOD)
            v -= MOD;
        return *this;
    }
    Mint &operator-=(const Mint &o) {
        if ((v -= o.v) < 0)
            v += MOD;
        return *this;
    }
    Mint &operator*=(const Mint &o) {
        v = (long long)v * o.v % MOD;
        return *this;
    }
    // MOD must be prime
    Mint &operator/=(const Mint &o) { return *this *= o.inv(); }

    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    // MOD must be prime
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }
    Mint operator-() const { return Mint(-v); }
    Mint &operator++() { return *this += 1; }
    Mint &operator--() { return *this -= 1; }

    friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }
    friend bool operator!=(const Mint &a, const Mint &b) { return a.v != b.v; }

    Mint pow(long long exp) const {
        Mint res = 1, base = *this;
        for (; exp > 0; exp >>= 1) {
            if (exp & 1)
                res *= base;
            base *= base;
        }
        return res;
    }

    // MOD must be prime
    Mint inv() const { return pow(MOD - 2); }

    friend ostream &operator<<(ostream &os, const Mint &m) { return os << m.v; }
    friend istream &operator>>(istream &is, Mint &m) {
        long long x;
        is >> x;
        m = Mint(x);
        return is;
    }
};
using mint = Mint<1000000007>; // or 998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Comb comb(1e7, MOD);

    int T;
    cin >> T;
    while (T--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;

        mint path1 = comb.nCr(a + b, a);
        mint path2 = comb.nCr(n + m - a - b, n - a);

        cout << path1 * path2 << "\n";
    }
    return 0;
}
