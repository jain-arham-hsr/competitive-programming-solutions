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

int to_bits(vector<int> segs) {
    int res = 0;
    for (auto x : segs) {
        res += (1 << x);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> disp(7);
    for (auto &x : disp)
        cin >> x;

    vector<vector<int>> digits = {{0, 1, 2, 4, 5, 6},
                                  {2, 5},
                                  {0, 2, 3, 4, 6},
                                  {0, 2, 3, 5, 6},
                                  {1, 2, 3, 5},
                                  {0, 1, 3, 5, 6},
                                  {0, 1, 3, 4, 5, 6},
                                  {0, 2, 5},
                                  {
                                      0,
                                      1,
                                      2,
                                      3,
                                      4,
                                      5,
                                      6,
                                  },
                                  {0, 1, 2, 3, 5, 6}};

    vector<int> st;
    if (disp[0][1] == '#')
        st.push_back(0);
    if (disp[1][0] == '#')
        st.push_back(1);
    if (disp[1][3] == '#')
        st.push_back(2);
    if (disp[3][1] == '#')
        st.push_back(3);
    if (disp[4][0] == '#')
        st.push_back(4);
    if (disp[4][3] == '#')
        st.push_back(5);
    if (disp[6][1] == '#')
        st.push_back(6);

    vector<int> res;
    for (int i = 0; i < 100; i++) {
        int dig1 = i % 10;
        int dig2 = i / 10;
        int curr = 0;
        curr ^= to_bits(digits[dig1]);
        if (dig2 != 0)
            curr ^= to_bits(digits[dig2]);
        if (curr == to_bits(st)) {
            res.push_back(i);
        };
    }

    for (auto &x : res)
        cout << x << "\n";

    if (!res.size())
        cout << "impossible" << "\n";

    return 0;
}
