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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int changeTo = lcm(gcd(a[i], a[i - 1]), gcd(a[i], a[i + 1]));
            if ((a[i] != changeTo && changeTo < b[i]) ||
                (a[i] != 2 * changeTo && 2 * changeTo < b[i])) {
                res++;
            }
        }
        int initGcd = gcd(a[0], a[1]);
        int lastGcd = gcd(a[n - 1], a[n - 2]);
        if ((a[0] != initGcd && initGcd < b[0]) ||
            (a[0] != 2 * initGcd && 2 * initGcd < b[0]))
            res++;
        if ((a[n - 1] != lastGcd && lastGcd < b[n - 1]) ||
            (a[n - 1] != 2 * lastGcd && 2 * lastGcd < b[n - 1]))
            res++;
        cout << res << "\n";
    }
    return 0;
}
