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
        int n;
        cin >> n;

        string t, b;
        cin >> t >> b;

        string resStr(n + 1, '0');

        resStr[0] = t[0];
        resStr[n] = b[n - 1];

        int ways = 1;
        bool topRow = true;

        for (int i = 1; i < n; i++) {
            if (topRow) {
                if (t[i] < b[i - 1]) {
                    resStr[i] = t[i];
                    ways = 1;
                } else if (b[i - 1] < t[i]) {
                    resStr[i] = b[i - 1];
                    topRow = false;
                } else {
                    resStr[i] = t[i];
                    ways++;
                }
            } else {
                resStr[i] = b[i - 1];
            }
        }

        cout << resStr << "\n" << ways << "\n";
    }
    return 0;
}
