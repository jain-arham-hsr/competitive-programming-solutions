#include <bits/stdc++.h>
using namespace std;

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
        int p, q;
        cin >> p >> q;
        long long total = p + 2 * q;
        bool exists = false;
        pair<int, int> ans = {-1, -1};
        for (int i = 1; i < 1e5; i++) {
            long long l = i - 1, r = 1e9 + 1;
            while (l < r - 1) {
                long long mid = l + (r - l) / 2;
                long long curr = i + mid + 2 * mid * i;
                if (curr == total) {
                    ans = {i, mid};
                    exists = true;
                    break;
                } else if (curr < total) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (exists)
                break;
        }
        if (exists)
            cout << ans.first << " " << ans.second << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}
