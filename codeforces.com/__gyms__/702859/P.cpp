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

    int n, bCap, aCap;
    cin >> n >> bCap >> aCap;

    vector<int> s(n);
    for (auto &x : s)
        cin >> x;

    int dist = 0;

    int a = aCap, b = bCap;

    watch(dist, b, a);
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            if (a > 0) {
                a--;
                dist++;
            } else if (b > 0) {
                b--;
                dist++;
            } else
                break;
        } else {
            if (b > 0 && aCap - a > 0) {
                b--;
                a++;
                dist++;
            } else if (a > 0) {
                a--;
                dist++;
            } else if (b > 0) {
                b--;
                dist++;
            } else
                break;
        }
        watch(dist, b, a);
    }

    cout << dist << "\n";

    return 0;
}
