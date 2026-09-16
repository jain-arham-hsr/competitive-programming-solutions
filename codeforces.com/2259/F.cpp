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
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        string s;
        cin >> s;

        int zeroCnt = 0;
        int oneCnt = 0;
        ll inv = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1)
                oneCnt++;
            else {
                zeroCnt++;
                inv += oneCnt;
            }
        }

        cout << inv << " ";

        int l = -1;
        int r = n;

        while (l + 1 < n && a[l + 1] == 0)
            l++;
        while (r - 1 >= 0 && a[r - 1] == 1)
            r--;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                l++;
                inv -= oneCnt - n + min(n - 1, r);
            } else {
                r--;
                inv -= zeroCnt - max(0, l);
            }
            watch(l, r);
            cout << max(0LL, inv) << " ";
        }
        cout << "\n";
    }
    return 0;
}
