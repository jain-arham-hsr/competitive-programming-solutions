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

    ll n, k, m, c, d;
    cin >> n >> k >> m >> c >> d;

    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> a_sorted = a;
    sort(rall(a_sorted));

    ll kth_largest = a_sorted[k - 1];

    set<ll> kth_largest_indices;
    ll max_pos = 1;
    for (ll i = 0; i < n; i++) {
        if (a[i] == kth_largest) {
            kth_largest_indices.insert(i);
            max_pos = max(max_pos, min(m, i + 1));
        }
    }

    vector<ll> to_remove_ind;

    for (auto x : kth_largest_indices) {
        ll x_pos = min(m, x + 1);
        if (x_pos < max_pos) {
            to_remove_ind.push_back(x);
        }
    }

    for (int i = 0; i < to_remove_ind.size(); i++) {
        kth_largest_indices.erase(to_remove_ind[i]);
    }

    vector<int> nums_greater(n);

    for (int i = 0; i < m; i++) {
        nums_greater[i] = a[i] > kth_largest;
        if (i > 0)
            nums_greater[i] += nums_greater[i - 1];
    }

    for (int i = m; i < n; i++) {
        nums_greater[i] -= a[i - m] > kth_largest;
        nums_greater[i] += a[i] > kth_largest;
        nums_greater[i] += nums_greater[i - 1];
    }

    int max_nums_greater = 0;

    for (auto x : kth_largest_indices) {
        max_nums_greater = max(max_nums_greater, nums_greater[x + m - max_pos]);
    }

    to_remove_ind = {};

    for (auto x : kth_largest_indices) {
        if (nums_greater[x + m - max_pos] == max_nums_greater) {
            to_remove_ind.push_back(x);
        }
    }

    for (int i = 0; i < to_remove_ind.size(); i++) {
        kth_largest_indices.erase(to_remove_ind[i]);
    }

    vector<int> sum_range(n);

    for (int i = 0; i < m; i++) {
        sum_range[i] = a[i];
        if (i > 0)
            sum_range[i] += sum_range[i - 1];
    }

    for (int i = m; i < n; i++) {
        sum_range[i] -= a[i - m];
        sum_range[i] += a[i];
        sum_range[i] += sum_range[i - 1];
    }

    return 0;
}
