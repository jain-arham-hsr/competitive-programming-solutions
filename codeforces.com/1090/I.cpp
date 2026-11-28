#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
    reverse(all(v));
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

ull MOD = (1LL << 32);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n, l, r, x, y, z, b1, b2;
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;

        x = x % MOD;
        y = y % MOD;
        z = z % MOD;

        vector<ll> b(n + 1);
        b[1] = b1 % MOD;
        b[2] = b2 % MOD;

        for (int i = 3; i <= n; i++) {
            b[i] =
                (((b[i - 2] * x) % MOD + (b[i - 1] * y) % MOD) % MOD + z) % MOD;
        }

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = (b[i] % (r - l + 1)) + l;
        }

        ll res = LLONG_MAX;

        set<ll> numsofar;

        bool ok = false;

        for (int i = n; i > 0; i--) {
            auto it = numsofar.upper_bound(a[i]);

            if (it != numsofar.end()) {
                ok = true;
                res = min(res, a[i] * (*it));
            }

            if (numsofar.size() > 0) {
                ll max_ele = *prev(numsofar.end());
                if (max_ele > a[i]) {
                    ok = true;
                    res = min(res, a[i] * max_ele);
                }
            }

            numsofar.insert(a[i]);
        }

        if (!ok)
            cout << "IMPOSSIBLE\n";
        else
            cout << res << "\n";
    }
    return 0;
}
