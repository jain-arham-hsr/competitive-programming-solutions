#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
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
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        bool consecOnes = false;
        bool consecZeroes = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                if (s[i] == '0')
                    consecZeroes = true;
                else
                    consecOnes = true;
            }
        }
        bool isTGood = true;
        for (int i = 1; i < m; i++) {
            if (t[i] == t[i - 1]) {
                isTGood = false;
                break;
            }
        }
        if ((consecZeroes || consecOnes) && !isTGood)
            cout << "NO\n";
        else if (consecZeroes && (t[0] == '0' || t[m - 1] == '0'))
            cout << "NO\n";
        else if (consecOnes && (t[0] == '1' || t[m - 1] == '1'))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
