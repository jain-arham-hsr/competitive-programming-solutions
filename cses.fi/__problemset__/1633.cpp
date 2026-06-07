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

int MOD = 1e9 + 7;

ll findNumWays(vector<int> &dp, int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    ll numWays = 0;
    numWays = (numWays + findNumWays(dp, n - 1)) % MOD;
    numWays = (numWays + findNumWays(dp, n - 2)) % MOD;
    numWays = (numWays + findNumWays(dp, n - 3)) % MOD;
    numWays = (numWays + findNumWays(dp, n - 4)) % MOD;
    numWays = (numWays + findNumWays(dp, n - 5)) % MOD;
    numWays = (numWays + findNumWays(dp, n - 6)) % MOD;
    return dp[n] = numWays;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << findNumWays(dp, n);

    return 0;
}
