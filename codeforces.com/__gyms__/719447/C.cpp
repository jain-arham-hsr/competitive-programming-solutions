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

    ull a, b, c, t;
    cin >> a >> b >> c >> t;

    vector<ull> lcms = {a * b / gcd(a, b), b * c / gcd(b, c),
                        a * c / gcd(a, c)};

    ull res = 0;

    for (int i = 1; i < (1 << 3); i++) {
        i128 curr = 1;
        int hamming = 0;

        for (int j = 0; j < 3; j++) {
            int bit = (1 << j);
            if (bit & i) {
                hamming++;
                curr = curr * lcms[j] / gcd(ll(curr), lcms[j]);
                if (curr > t) {
                    goto next;
                }
            }
        }

        if (hamming % 2 != 0)
            res += t / curr;
        else
            res -= t / curr;
    next:;
    }

    cout << res << "\n";

    return 0;
}
