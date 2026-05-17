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

int maxTotalVal(vector<vector<int>> &dp, vector<int> &vals,
                vector<int> &weights, int level, int remCap) {
    if (level < 0)
        return 0;
    int valWhenIncluded = 0;
    int valWhenExcluded = 0;
    if (level > 0 && remCap >= 0 && dp[level - 1][remCap] != -1) {
        valWhenExcluded = dp[level - 1][remCap];
    } else {
        valWhenExcluded = maxTotalVal(dp, vals, weights, level - 1, remCap);
    }

    if (level > 0 && remCap - weights[level] >= 0 &&
        dp[level - 1][remCap - weights[level]] != -1) {
        valWhenIncluded = dp[level - 1][remCap] + vals[level];
    } else {
        valWhenIncluded =
            maxTotalVal(dp, vals, weights, level - 1, remCap - weights[level]) +
            vals[level];
    }
    return dp[level][remCap] = max(valWhenExcluded, valWhenIncluded);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, W;
    cin >> n >> W;
    vector<int> vals(n);
    for (auto &x : vals)
        cin >> x;
    vector<int> weights(n);
    for (auto &x : weights)
        cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << maxTotalVal(dp, vals, weights, n - 1, W);

    return 0;
}
