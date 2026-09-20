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

        vector<int> prefMax(n);
        vector<int> suffMax(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(nums[i], prefMax[i - 1]);
        }

        suffMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMax[i] = max(nums[i], suffMax[i + 1]);
        }

        ll totalBlocks = accumulate(nums.begin(), nums.end(), 0LL);

        ll res = 0;

        for (int i = 0; i < n; i++) {
            int prevPrefMax = 0, nextSuffMax = 0;
            if (i > 0)
                prevPrefMax = prefMax[i - 1];
            if (i < n - 1)
                nextSuffMax = suffMax[i + 1];

            ll restMax = max(prevPrefMax, nextSuffMax);

            ll curr;
            if (restMax * (n - 1) > totalBlocks) {
                curr = restMax * (n - 1) - totalBlocks;
            } else {
                curr = (n - 1 - totalBlocks % (n - 1)) % (n - 1);
            }
            watch(curr);
            res = max(res, curr);
        }

        cout << res << "\n";
    }
    return 0;
}
