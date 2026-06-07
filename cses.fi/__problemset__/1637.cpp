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

int findMinSteps(int n) {
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    if (dp[n] != -2)
        return dp[n];
    int minSteps = INT_MAX;
    int nCopy = n;
    while (nCopy > 0) {
        int dig = nCopy % 10;
        nCopy /= 10;
        if (dig == 0)
            continue;
        int subRes = findMinSteps(n - dig);
        if (subRes != -1)
            minSteps = min(minSteps, 1 + subRes);
    }
    return dp[n] = minSteps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill((int *)begin(dp), (int *)end(dp), -2);

    int n;
    cin >> n;

    cout << findMinSteps(n);

    return 0;
}
