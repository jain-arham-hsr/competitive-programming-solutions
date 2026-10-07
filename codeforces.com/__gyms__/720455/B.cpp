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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;

        vector<ll> b(n);
        for (auto &x : b)
            cin >> x;

        ll sumA = accumulate(a.begin(), a.end(), 0LL);
        ll sumB = accumulate(b.begin(), b.end(), 0LL);

        bool ok = true;

        for (int i = n - 2; i >= 0; i--) {
            if (a[i + 1] > b[i + 1] || (b[i + 1] - a[i + 1]) % 2 != 0) {
                ok = false;
                break;
            }
            b[i] += (b[i + 1] - a[i + 1]) / 2;
        }

        if (b[0] != a[0])
            ok = false;

        if (!ok)
            cout << -1 << "\n";
        else
            cout << sumB - sumA << "\n";
    }
    return 0;
}
