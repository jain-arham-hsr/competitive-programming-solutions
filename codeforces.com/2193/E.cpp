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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;

        set<int> uNums(nums.begin(), nums.end());

        vector<int> dp(n + 1, -1);

        for (auto num : nums) {
            dp[num] = 1;
        }

        for (int i = 1; i < n; i++) {
            if (dp[i] == -1)
                continue;
            for (auto x : uNums) {
                if (i > n / x) {
                    break;
                }
                int prod = i * x;
                if (dp[prod] == -1)
                    dp[prod] = dp[i] + 1;
                else
                    dp[prod] = min(dp[prod], dp[i] + 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
