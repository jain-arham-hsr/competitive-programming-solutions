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

int dp[1000][1000];
int MOD = 1e9 + 7;

int findNumPaths(vector<string> &grid, int x, int y) {
    if (x >= grid.size() || y >= grid.size() || grid[y][x] == '*')
        return 0;
    if (x == grid.size() - 1 && y == grid.size() - 1)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    return dp[x][y] =
               (findNumPaths(grid, x + 1, y) + findNumPaths(grid, x, y + 1)) %
               MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &x : grid)
        cin >> x;

    fill((int *)begin(dp), (int *)end(dp), -1);

    cout << findNumPaths(grid, 0, 0);

    return 0;
}
