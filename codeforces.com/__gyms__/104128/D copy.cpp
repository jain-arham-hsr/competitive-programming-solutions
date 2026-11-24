#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

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

_INT32_T main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int T;
    // cin >> T;
    // while (T--) {
    // code here
    int n, k, m, c, d;
    cin >> n >> k >> m >> c >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0;
    vector<int> temp = a;
    sort(temp.rbegin(), temp.rend());

    l = temp[k - 1];
    watch(l);

    int largest = 0;

    if (d == 0) {
        

        

        for (int i = 0; i < n; i++) {
            if (a[i] == l) {
                a[i] += c;
                break;
            }
        }
        sort(a.rbegin(), a.rend());
        largest = a[k - 1];

        cout << largest << endl;
        // }
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == l) {
            int cur = 0;
            if (i >= m - 1) {
                cur = m;
                largest = a[i] + (c + (cur - 1) * d);
                m--;
                while (m > 0) {
                    int lk = a[m - 1] + (c + (m - 1) * d);
                    a[m - 1] = lk;
                    m--;
                }
            } else {
                cur = i + 1;
                int rem = cur;
                while (rem < m) {
                    int lk = a[rem - 1] + (c + (rem - 1) * d);
                    a[rem - 1] = lk;
                    rem++;
                }

                while (cur > 0) {
                    int lk = a[cur - 1] + (c + (cur - 1) * d);
                    a[cur - 1] = lk;
                    cur--;
                }
            }

            break;
        }
    }
    sort(a.rbegin(), a.rend());
    largest = a[k - 1];

    cout << largest << endl;
    // }
    return 0;
}
