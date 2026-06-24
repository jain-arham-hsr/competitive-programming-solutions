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
        sort(nums.begin(), nums.end());

        bitset<32> matchNum(nums[0]);
        int mostSigBit = -1;

        for (int i = 0; i < 32; i++) {
            if (matchNum[i] > 0)
                mostSigBit = i;
        }

        int res = 0;

        for (int i = 1; i < n; i++) {
            bitset<32> currNum(nums[i]);
            int currMostSig = -1;

            for (int j = 0; j < 32; j++) {
                if (currNum[j] > 0)
                    currMostSig = j;
            }
            res += currMostSig - mostSigBit;
            for (int j = mostSigBit; j >= 0; j--) {
                if (matchNum[j] != currNum[j + currMostSig - mostSigBit]) {
                    res += (i + 1) * (j + 1);
                    matchNum >>= j + 1;
                    mostSigBit -= (j + 1);
                    break;
                }
            }
        }

        cout << res << "\n";
    }
    return 0;
}
