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

int dp[1001][101][2];

int findMaxProfit(vector<int> &diff, int curr, int k, bool holding) {
    if (curr == diff.size() || k == 0)
        return 0;

    if (dp[curr][k][holding] != -1)
        return dp[curr][k][holding];

    int maxProfit = 0;

    if (holding) {
        maxProfit = max(maxProfit, diff[curr] + findMaxProfit(diff, curr + 1,
                                                              k - 1, !holding));
        maxProfit = max(maxProfit,
                        diff[curr] + findMaxProfit(diff, curr + 1, k, holding));
    } else {
        maxProfit = max(maxProfit, findMaxProfit(diff, curr + 1, k, !holding));
        maxProfit = max(maxProfit, findMaxProfit(diff, curr + 1, k, holding));
    }

    return dp[curr][k][holding] = maxProfit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    fill((int *)begin(dp), (int *)end(dp), -1);

    vector<int> diff(n);
    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
    }

    cout << findMaxProfit(diff, 0, k, false);

    return 0;
}
