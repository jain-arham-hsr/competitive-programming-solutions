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

        int l = -1, r = n + 1;
        while (l < r - 1) {
            int mid = l + (r - l) / 2;

            int p = 1, q = 1;
            bool valid = true;
            watch(mid);
            for (int i = 0; i < n; i++) {
                int currOp = nums[i];
                if (nums[i] == 0) {
                    if (i < mid) {
                        currOp = 1;
                    } else {
                        currOp = -1;
                    }
                }
                if (currOp == 1) {
                    p += 1;
                    q += 1;
                } else {
                    if (q < 2) {
                        valid = false;
                        break;
                    }
                    q -= 1;
                }
                watch(p, q);
            }

            if (valid) {
                r = mid;
            } else {
                l = mid;
            }
        }

        watch(r);

        if (r == n + 1) {
            int p = 1, q = 1;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                int currOp = nums[i];
                if (nums[i] == 0) {
                    if (i < r) {
                        currOp = 1;
                    } else {
                        currOp = -1;
                    }
                }
                if (currOp == 1) {
                    p += 1;
                    q += 1;
                } else {
                    if (q < 2) {
                        valid = false;
                        break;
                    }
                    q -= 1;
                }
                watch(p, q);
            }

            if (!valid) {
                cout << -1 << "\n";
                continue;
            }
        }

        ll neg = count(all(nums), -1);
        ll neutral = 0;
        ll pos = count(all(nums), 1);
        if (r <= n) {
            neutral += count(nums.begin() + r, nums.end(), 0);
            pos += count(nums.begin(), nums.begin() + r, 0);
        }

        watch(neg, neutral, pos);

        ll total_p = 1 + pos;
        ll total_q = 1 + pos - neg;

        watch(total_p, total_q);

        ll max_avg_p = total_p + neutral, max_avg_q = total_q + neutral;

        for (int i = 0; i < neutral; i++) {
            ll curr_p = total_p + i;
            ll curr_q = total_q + i - (neutral - i);
            if (compare_frac({curr_p, curr_q}, {max_avg_p, max_avg_q})) {
                max_avg_p = curr_p;
                max_avg_q = curr_q;
            }
        }

        ll factor = gcd(max_avg_p, max_avg_q);
        cout << max_avg_p / factor << " " << max_avg_q / factor << "\n";
    }
    return 0;
}
