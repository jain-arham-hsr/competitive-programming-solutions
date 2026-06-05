#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int p, q;
        cin >> p >> q;
        long long s = 2 * p + 4 * q + 1;
        bool ok = false;
        for (long long i = 1; i * i <= s; i++) {
            if (s % i == 0 && i % 2 == 1 && (s / i) % 2 == 1) {
                int n = (i - 1) / 2;
                int m = (s / i - 1) / 2;
                if (n < 1 || m < 1 || m * (n + 1) < q || n * (m + 1) < q)
                    continue;
                cout << n << " " << m << "\n";
                ok = true;
                break;
            }
        }
        if (!ok)
            cout << -1 << "\n";
    }
    return 0;
}
