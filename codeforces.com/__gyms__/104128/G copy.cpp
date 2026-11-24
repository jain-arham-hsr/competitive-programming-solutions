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

bool compare_frac(pair<int, int> frac1, pair<int, int> frac2) {
    return (ll)frac1.first * (ll)frac2.second >
           (ll)frac1.second * (ll)frac2.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;

        vector<pair<ll, ll>> c(n + 1);
        vector<pair<ll, ll>> m(n + 1);

        c[0] = {1, 1};
        m[0] = {1, 1};

        bool ok = true;

        for (int i = 1; i <= n; i++) {
            int op = nums[i - 1];
            if (op == 1) {
                c[i] = {c[i - 1].first + 1, c[i - 1].second + 1};
                m[i] = {m[i - 1].first + 1, m[i - 1].second + 1};
            } else if (op == -1) {
                if (c[i - 1].second < 2 && m[i - 1].second < 2) {
                    ok = false;
                    continue;
                } else if (m[i - 1].second < 2) {
                    c[i] = {c[i - 1].first, c[i - 1].second - 1};
                    m[i] = c[i];
                } else {
                    c[i] = {c[i - 1].first, c[i - 1].second - 1};
                    m[i] = {m[i - 1].first, m[i - 1].second - 1};
                }
            } else {
                if (compare_frac({c[i - 1].first + 1, c[i - 1].second + 1},
                                 {m[i - 1].first + 1, m[i - 1].second + 1})) {
                    c[i] = {c[i - 1].first + 1, c[i - 1].second + 1};
                } else {
                    c[i] = {m[i - 1].first + 1, m[i - 1].second + 1};
                }
                if (m[i - 1].second < 2) {
                    m[i] = c[i];
                } else {
                    if (compare_frac({c[i - 1].first, c[i - 1].second - 1},
                                     {m[i - 1].first, m[i - 1].second - 1})) {
                        m[i] = {c[i - 1].first, c[i - 1].second - 1};
                    } else {
                        m[i] = {m[i - 1].first, m[i - 1].second - 1};
                    }
                }
            }
            watch(c[i], m[i]);
        }

        if (!ok)
            cout << -1 << "\n";
        else {

            ll numer, denom;
            if (compare_frac(c[n], m[n])) {
                numer = c[n].first;
                denom = c[n].second;
            } else {
                numer = m[n].first;
                denom = m[n].second;
            }

            cout << numer / gcd(numer, denom) << " "
                 << denom / gcd(numer, denom) << "\n";
        }
    }
    return 0;
}
