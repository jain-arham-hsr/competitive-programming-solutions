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

long long findValidWays(vector<vector<int>> &dp, int N, bool threeAllowed) {

    if (N < 0)
        return 0;

    if (dp[N][threeAllowed] != -1)
        return dp[N][threeAllowed];

    if (N == 0)
        return dp[N][threeAllowed] = 1;
    if (threeAllowed) {
        return dp[N][threeAllowed] = (findValidWays(dp, N - 1, true) +
                                      findValidWays(dp, N - 2, true) +
                                      findValidWays(dp, N - 3, false)) %
                                     MOD;
    } else {
        return dp[N][threeAllowed] = (findValidWays(dp, N - 1, true) +
                                      findValidWays(dp, N - 2, true)) %
                                     MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(2, -1));

    cout << findValidWays(dp, N, true);

    return 0;
}
