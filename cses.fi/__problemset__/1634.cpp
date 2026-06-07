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

int dp[int(1e6) + 1];

int findMinCoins(int x, vector<int> &c) {
    if (x < 0)
        return -1;
    if (x == 0)
        return 0;
    if (dp[x] != -2)
        return dp[x];
    int minCoins = -1;
    for (int i = 0; i < c.size(); i++) {
        int subres = findMinCoins(x - c[i], c);
        if (subres == -1)
            continue;
        if (minCoins == -1)
            minCoins = 1 + subres;
        else
            minCoins = min(minCoins, 1 + subres);
    }
    return dp[x] = minCoins;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill((int *)begin(dp), (int *)end(dp), -2);

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (auto &x : c)
        cin >> x;

    cout << findMinCoins(x, c);

    return 0;
}
