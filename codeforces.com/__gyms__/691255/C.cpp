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

int findMinCount(vector<int> &dp, vector<int> &coins, int sum) {
    int minCount = -1;

    if (dp[sum] != -2)
        return dp[sum];

    if (sum == 0)
        return 0;

    for (int i = 0; i < coins.size(); i++) {
        if (sum - coins[i] < 0)
            continue;
        int subres = findMinCount(dp, coins, sum - coins[i]);
        if (subres == -1)
            continue;
        int count = 1 + subres;
        if (minCount == -1)
            minCount = count;
        else
            minCount = min(minCount, count);
    }
    return dp[sum] = minCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, sum;
    cin >> n >> sum;

    vector<int> coins(n);
    for (auto &x : coins)
        cin >> x;

    vector<int> dp(sum + 1, -2);

    cout << findMinCount(dp, coins, sum);

    return 0;
}
