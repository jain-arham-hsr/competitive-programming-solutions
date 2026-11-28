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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    string s1, s2;
    cin >> s1 >> s2;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            a++;
        else
            b++;
    }

    if (t < (a + 1) / 2) {
        cout << -1;
        return 0;
    }

    string res(n, '0');

    int p = 2 * min(a, t) - a;
    t -= p;

    int q = a - p;
    t -= q / 2;

    int r = q / 2;
    q /= 2;

    int u = t;

    watch(p, q, u);

    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            if (u > 0) {
                res[i] = (s1[i] == 'a') ? 'b' : 'a';
                u--;
            } else {
                res[i] = s1[i];
            }
        } else {
            if (p > 0) {
                if (s1[i] != 'a' && s2[i] != 'a') {
                    res[i] = 'a';
                } else if (s1[i] != 'b' && s2[i] != 'b') {
                    res[i] = 'b';
                } else {
                    res[i] = 'c';
                }
                p--;
            } else if (q > 0) {
                res[i] = s2[i];
                q--;
            } else {
                res[i] = s1[i];
            }
        }
    }

    cout << res;

    return 0;
}
