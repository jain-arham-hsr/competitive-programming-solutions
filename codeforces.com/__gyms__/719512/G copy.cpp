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

    // vector<int> freq(5e5 + 1);
    vector<int> freq(50);

    ll mid = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                freq[(abs(mid - i) << 1) + (abs(mid - j) << 1)]++;
                freq[(abs(mid - (i + 1)) << 1) + (abs(mid - j) << 1)]++;
                freq[(abs(mid - i) << 1) + (abs(mid - (j + 1)) << 1)]++;
                freq[(abs(mid - (i + 1)) << 1) + (abs(mid - (j + 1)) << 1)]++;
            }
            watch(freq);
        }
    }

    ll maxFreq = 0;
    ll val = 0;

    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            val = i;
        }
    }

    watch(freq);

    cout << fixed << setprecision(10) << sqrtl(val) << "\n";

    return 0;
}
