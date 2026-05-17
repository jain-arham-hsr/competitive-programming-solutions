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
        int n, k, p;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        cin >> p;
        p--;
        int leftSegments = 1;
        int rightSegments = 1;
        int last = a[0];
        for (int i = 1; i <= p; i++) {
            if (a[i] != last) {
                leftSegments++;
                last = a[i];
            }
        }
        last = a[p];
        for (int i = p + 1; i < n; i++) {
            if (a[i] != last) {
                rightSegments++;
                last = a[i];
            }
        }
        if (a[0] == a[p])
            leftSegments--;
        if (a[n - 1] == a[p])
            rightSegments--;
        cout << max(leftSegments, rightSegments) << "\n";
    }
    return 0;
}
