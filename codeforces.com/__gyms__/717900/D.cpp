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

ll ilog(long long num) {
    long long curr = 1;
    int i = 0;
    while (curr < num) {
        curr *= 2;
        i++;
    }
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(n);

        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        vector<ll> factor(n);

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (b[i] != 0) {
                    ok = false;
                    break;
                } else {
                    continue;
                }
            }
            if (b[i] % a[i] != 0 && b[i] != m) {
                ok = false;
                break;
            }
            factor[i] = ilog((b[i] + a[i] - 1) / a[i]);
            if (a[i] * (1LL << factor[i]) != b[i] && b[i] != m) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << -1 << "\n";
            continue;
        }

        ll curr = 0;

        ll res = 0;

        for (int i = 0; i < n; i++) {
            if (factor[i] > curr) {
                res += factor[i] - curr;
            }
            if ((b[i] == m && factor[i] < curr) || b[i] == 0)
                continue;
            curr = factor[i];
        }

        cout << res << "\n";
    }
    return 0;
}
