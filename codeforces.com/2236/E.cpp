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

        vector<int> freq(n + 1);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        int res = 0;

        vector<vector<bool>> segExists(n + 1, vector<bool>(n + 1));

        for (int i = 0; i < n; i++) {
            vector<bool> exists(n + 1);
            int maxNum = nums[i];
            int minNum = nums[i];
            for (int j = i; j < n; j++) {
                if (exists[nums[j]])
                    break;
                exists[nums[j]] = true;
                maxNum = max(maxNum, nums[j]);
                minNum = min(minNum, nums[j]);
                if (maxNum - minNum == j - i) {
                    int l = j - i + 1;
                    segExists[minNum][maxNum] = true;
                    if (minNum - l >= 1 && segExists[minNum - l][maxNum - l] ||
                        maxNum + l <= n && segExists[minNum + l][maxNum + l]) {
                        res = max(res, j - i + 1);
                    }
                }
            }
        }

        cout << res << "\n";
    }
    return 0;
}
