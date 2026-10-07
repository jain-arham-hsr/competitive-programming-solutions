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

    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &x : grid)
        cin >> x;

    bool isCorner = false;
    int minRing = n + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '#')
                continue;
            int ring = min(min(i, j), min(n - i - 1, n - j - 1));
            if (ring < minRing) {
                minRing = ring;
                if (grid[ring][ring] == '#' ||
                    grid[ring][n - 1 - ring] == '#' ||
                    grid[n - 1 - ring][ring] == '#' ||
                    grid[n - 1 - ring][n - 1 - ring] == '#') {
                    isCorner = true;
                } else {
                    isCorner = false;
                }
            }
        }
    }

    watch(minRing);
    int radius = n / 2 - 1 - minRing;
    watch(radius);

    long double res = radius;
    if (isCorner)
        res *= sqrtl(2);

    cout << fixed << setprecision(10) << res << "\n";

    return 0;
}
