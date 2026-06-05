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

int findMinRestDays(vector<vector<vector<int>>> &dp, int curr, vector<int> &a,
                    bool canGym, bool canContest) {
    if (curr >= a.size())
        return 0;

    if (dp[canGym][canContest][curr] != -1)
        return dp[canGym][canContest][curr];
    int minRestDays = a.size() - curr + 1;
    if (canGym && a[curr] > 1) {
        minRestDays =
            min(minRestDays, findMinRestDays(dp, curr + 1, a, false, true));
    }
    if (canContest && a[curr] % 2 == 1) {
        minRestDays =
            min(minRestDays, findMinRestDays(dp, curr + 1, a, true, false));
    }
    minRestDays =
        min(minRestDays, 1 + findMinRestDays(dp, curr + 1, a, true, true));
    return dp[canGym][canContest][curr] = minRestDays;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<vector<vector<int>>> dp(
        2, vector<vector<int>>(2, vector<int>(n + 1, -1)));

    cout << findMinRestDays(dp, 0, a, true, true);

    return 0;
}
