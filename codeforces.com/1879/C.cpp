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
ostream &operator<<(ostream &os, const T &c);

template <typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &t) {
    os << "(";
    apply(
        [&](auto &...x) {
            bool f = true;
            ((os << (f ? f = false, "" : ", ") << x), ...);
        },
        t);
    return os << ")";
}

template <typename T>
auto operator<<(ostream &os, const T &x) -> decltype(x._fields(), os) {
    return os << x._fields();
}

template <typename T, typename C>
ostream &operator<<(ostream &os, stack<T, C> s) {
    vector<T> v;
    for (; !s.empty(); s.pop())
        v.push_back(s.top());
    reverse(v.begin(), v.end());
    return os << v;
}

template <typename T, typename C>
ostream &operator<<(ostream &os, queue<T, C> q) {
    os << "{";
    for (bool f = true; !q.empty(); q.pop())
        os << (f ? f = false, "" : ", ") << q.front();
    return os << "}";
}

template <typename T, typename C, typename Cmp>
ostream &operator<<(ostream &os, priority_queue<T, C, Cmp> pq) {
    os << "{";
    for (bool f = true; !pq.empty(); pq.pop())
        os << (f ? f = false, "" : ", ") << pq.top();
    return os << "}";
}

template <typename T, typename> ostream &operator<<(ostream &os, const T &c) {
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

#define FIELDS(...)                                                            \
    auto _fields() const { return tie(__VA_ARGS__); }                          \
    template <typename O> bool operator<(const O &o) const {                   \
        return _fields() < o._fields();                                        \
    }                                                                          \
    template <typename O> bool operator>(const O &o) const {                   \
        return _fields() > o._fields();                                        \
    }                                                                          \
    template <typename O> bool operator==(const O &o) const {                  \
        return _fields() == o._fields();                                       \
    }                                                                          \
    template <typename O> bool operator!=(const O &o) const {                  \
        return _fields() != o._fields();                                       \
    }

// ==================================================================== //

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

using mint = Mint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    vector<mint> fact(2e5 + 1);
    fact[0] = 1;

    for (int i = 1; i < fact.size(); i++) {
        fact[i] = fact[i - 1] * i;
    }

    while (T--) {
        string s;
        cin >> s;

        int n = s.size();

        ll minOps = 0;
        mint ways = 1;

        int curr = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                minOps += curr - 1;
                ways *= curr;
                curr = 1;
            } else {
                curr++;
            }
        }

        ways *= curr;
        minOps += curr - 1;

        cout << minOps << " " << ways * fact[minOps] << "\n";
    }
    return 0;
}
