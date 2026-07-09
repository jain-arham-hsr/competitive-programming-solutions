#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

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

int32_t main() {
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

        int numsTypes = 1;
        int totalNums = n;

        map<int, int> freqFreq;

        int currCnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                freqFreq[currCnt]++;
                currCnt = 1;
                numsTypes++;
            } else {
                currCnt++;
            }
        }
        freqFreq[currCnt]++;

        int rem = 0;

        int res = 0;

        for (auto x : freqFreq) {
            if (x.first <= rem)
                continue;
            if (k >= totalNums - (x.first - rem - 1) * numsTypes) {
                res += (k - totalNums) % numsTypes == 0;
                // if ((k - totalNums) % numsTypes == 0)
                //     watch(x.first, numsTypes, totalNums);
            }
            totalNums -= (x.first - rem) * numsTypes;
            // watch(totalNums);
            rem += x.first - rem;
            numsTypes -= x.second;
        }

        cout << res << "\n";
    }
    return 0;
}
