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

        int curr = -1;

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (curr == -1 && t[i] == 'B' && b[i] == 'B')
                continue;
            else if (t[i] == 'B' && b[i] == 'B') {
                curr = !curr;
            } else if (t[i] == 'B') {
                if (curr == -1)
                    curr = 0;
                else if (curr == 1)
                    ok = false;
            } else if (b[i] == 'B') {
                if (curr == -1)
                    curr = 1;
                else if (curr == 0)
                    ok = false;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
