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

        int minInd = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                minInd = i;
        }

        long double maxAvg =
            (nums[minInd] + nums[minInd + 1] + nums[minInd - 1]) * 1.0L / 3;

        maxAvg = max(maxAvg,
                     accumulate(nums.begin(), nums.begin() + minInd + 2, 0LL) *
                         1.0L / (minInd + 2));

        maxAvg =
            max(maxAvg, accumulate(nums.begin() + minInd - 1, nums.end(), 0LL) *
                            1.0L / (n - minInd + 1));

        maxAvg =
            max(maxAvg, accumulate(nums.begin(), nums.end(), 0LL) * 1.0L / n);

        cout << setprecision(20) << fixed << maxAvg << "\n";
    }
    return 0;
}
