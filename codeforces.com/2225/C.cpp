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
        int n;
        cin >> n;
        string r1, r2;
        cin >> r1 >> r2;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = r1[0] != r2[0];
        for (int i = 2; i <= n; i++) {
            int vertCost = r1[i - 1] != r2[i - 1];
            int horCost = (r1[i - 2] != r1[i - 1]) + (r2[i - 2] != r2[i - 1]);
            dp[i] = min(dp[i - 1] + vertCost, dp[i - 2] + horCost);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
