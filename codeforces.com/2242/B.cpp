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

        int oneExceeds = 0;
        int oneTwoExceeds = 0;

        int oneTwoExceedsReq = INT_MAX;
        bool valid = false;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == 1) {
                oneExceeds++;
                oneTwoExceeds++;
            } else if (nums[i] == 2) {
                oneExceeds--;
                oneTwoExceeds++;
            } else {
                oneExceeds--;
                oneTwoExceeds--;
            }
            if (oneTwoExceeds >= oneTwoExceedsReq) {
                valid = true;
                break;
            }
            if (oneExceeds >= 0)
                oneTwoExceedsReq = min(oneTwoExceedsReq, oneTwoExceeds);
        }

        cout << (valid ? "YES" : "NO") << "\n";
    }
    return 0;
}
