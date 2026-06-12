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

// int dp[1001][int(1e5) + 1];
int dp[5][11];

int findMaxPages(vector<int> &h, vector<int> &s, int i, int x) {
    if (i >= h.size() || x == 0)
        return 0;
    if (dp[i][x] != -1)
        return dp[i][x];
    int maxPages = 0;
    if (h[i] <= x)
        maxPages = max(maxPages, s[i] + findMaxPages(h, s, i + 1, x - h[i]));
    maxPages = max(maxPages, findMaxPages(h, s, i + 1, x));
    return dp[i][x] = maxPages;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> h(n);
    for (auto &x : h)
        cin >> x;
    vector<int> s(n);
    for (auto &x : s)
        cin >> x;

    fill((int *)begin(dp), (int *)end(dp), -1);

    // vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // dp[0][0] = 0;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= x; j++) {
    //         if (j + h[i] <= x)
    //             dp[i][j + h[i]] = max(dp[i][j] + s[i], dp[i][j + h[i]]);
    //     }
    // }

    // cout << dp[n - 1][x];

    cout << findMaxPages(h, s, 0, x) << "\n";

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
