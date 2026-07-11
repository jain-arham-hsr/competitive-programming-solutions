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

ll findMaxSum(vector<vector<vector<ll>>> &dp, vector<ll> &diffs, bool running,
              int ind, int k) {
    if (ind < 0)
        return 0;
    if (dp[running][k][ind] != -1)
        return dp[running][k][ind];
    ll res = 0;
    if (!running && k > 0) {
        res =
            max(res, diffs[ind] + findMaxSum(dp, diffs, true, ind - 1, k - 1));
    } else if (running) {
        res = max(res, diffs[ind] + findMaxSum(dp, diffs, true, ind - 1, k));
    }
    res = max(res, findMaxSum(dp, diffs, false, ind - 1, k));

    return dp[running][k][ind] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<ll> diff(n);

    for (int i = 0; i < n; i++) {
        diff[i] = b[i] - a[i];
    }

    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(11, vector<ll>(n, -1)));

    cout << accumulate(a.begin(), a.end(), 0LL) +
                findMaxSum(dp, diff, false, n - 1, k);

    return 0;
}
