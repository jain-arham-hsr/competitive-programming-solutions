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
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;

        vector<bool> exists(n + 1);
        for (int i = 0; i < n; i++) {
            exists[nums[i]] = true;
        }

        int mex = 0;
        for (int i = 0; i < n + 1; i++) {
            if (!exists[i]) {
                mex = i;
                break;
            }
        }

        k--;

        vector<int> init_arr(n + 1);

        for (int i = 0; i < n; i++) {
            init_arr[i] = mex;
            mex = nums[i];
        }

        init_arr[n] = mex;

        watch(init_arr);

        int init = n + 1 - (k % (n + 1));
        watch(init);

        // watch(nums[10]);

        for (int i = 0; i < n; i++) {
            watch((init + i) % (n + 1));
            cout << init_arr[(init + i) % (n + 1)] << " ";
        }
        cout << "\n";
    }
    return 0;
}
