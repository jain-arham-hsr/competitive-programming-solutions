#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        ll n, m;
        cin >> n >> m;
        ll n0 = n;
        int cnt2 = 0, cnt5 = 0;
        ll k = 1;
        while (n > 0 && n % 2 == 0) {
            n /= 2;
            cnt2++;
        }
        while (n > 0 && n % 5 == 0) {
            n /= 5;
            cnt5++;
        }
        while (cnt2 < cnt5 && k * 2 <= m) {
            cnt2++;
            k *= 2;
        }
        while (cnt5 < cnt2 && k * 5 <= m) {
            cnt5++;
            k *= 5;
        }
        while (k * 10 <= m) {
            k *= 10;
        }
        if (k == 1) {
            cout << n0 * m << endl;
        } else {
            k *= m / k; // 1 <= m/k < 10
            cout << n0 * k << endl;
        }
    }
    return 0;
}
