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

struct fight {
    int l;
    int r;
    int x;
};

struct brace {
    int terminal1;
    int pos;
    int terminal2;
    int x;

    FIELDS(terminal1, pos, terminal2, x);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<fight> fights(m);
    vector<brace> braces;

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        fights[i] = {l, r, x};
        braces.push_back({l, -(i + 1), r, x});
        braces.push_back({r, i + 1, l, x});
    }

    sort(braces.begin(), braces.end());

    vector<int> res(n + 1);

    watch(braces);

    stack<brace> st;
    stack<brace> aux;

    int p = 0;

    stack<pair<int, int>> xSt;

    for (int curr = 1; curr <= n; curr++) {
        while (p < braces.size() && braces[p].terminal1 == curr) {
            if ((!xSt.size() || xSt.top().first != braces[p].x) &&
                braces[p].pos < 0)
                xSt.push({braces[p].x, braces[p].terminal2});
            p++;
        }
        int setVal = xSt.top().first;
        if (curr == xSt.top().first) {
            pair<int, int> aux = xSt.top();
            xSt.pop();
            if (xSt.size())
                setVal = xSt.top().first;
            else
                setVal = 0;
            xSt.push(aux);
        }
        res[curr] = setVal;

        if (xSt.size() && curr == xSt.top().second)
            xSt.pop();

        watch(res);
    }

    watch(st);

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";

    return 0;
}
