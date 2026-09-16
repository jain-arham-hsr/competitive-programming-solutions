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

    vector<int> nDigTwoPowers = {8,         64,        512,     8192,
                                 65536,     524288,    8388608, 67108864,
                                 536870912, 1073741824};
    vector<int> nDigThreePowers = {9,         81,        729,     6561,
                                   59049,     531441,    4782969, 43046721,
                                   387420489, 1162261467};

    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        int twoDigCnt = a - c;
        int threeDigCnt = b - c;

        cout << (nDigTwoPowers[twoDigCnt] * int(pow(10, c - 1))) << " "
             << (nDigThreePowers[threeDigCnt] * int(pow(10, c - 1))) << "\n";
    }
    return 0;
}
