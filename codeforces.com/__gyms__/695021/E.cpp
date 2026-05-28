#include <bits/stdc++.h>
using namespace std;

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

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> seg;
    seg.reserve(n);

    int consecCnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            seg.push_back(consecCnt);
            consecCnt = 1;
        } else {
            consecCnt++;
        }
    }
    seg.push_back(consecCnt);
    watch(seg);

    int m = seg.size();

    vector<int> red = seg;
    vector<int> black = seg;

    for (int i = 0; i < m; i++) {
        if (i % 2 == 0)
            red[i] = 0;
        else
            black[i] = 0;
    }

    vector<int> segSum(m + 1);
    vector<int> redSum(m + 1);
    vector<int> blackSum(m + 1);
    partial_sum(seg.begin(), seg.end(), segSum.begin() + 1);
    partial_sum(red.begin(), red.end(), redSum.begin() + 1);
    partial_sum(black.begin(), black.end(), blackSum.begin() + 1);

    watch(seg);
    watch(segSum);
    watch(red);
    watch(redSum);
    watch(black);
    watch(blackSum);

    int l = 1;
    int maxSum = 0;
    for (int r = 1; r < m + 1; r++) {
        while (redSum[r] - redSum[l - 1] > k && l < r) {
            l++;
        }
        maxSum = max(segSum[r] - segSum[l - 1] +
                         min(redSum[m] - (redSum[r] - redSum[l - 1]),
                             k - (redSum[r] - redSum[l - 1])),
                     maxSum);
    }

    l = 1;
    for (int r = 1; r < m + 1; r++) {
        while (blackSum[r] - blackSum[l - 1] > k && l < r) {
            l++;
        }
        maxSum = max(segSum[r] - segSum[l - 1] +
                         min(blackSum[m] - (blackSum[r] - blackSum[l - 1]),
                             k - (blackSum[r] - blackSum[l - 1])),
                     maxSum);
    }

    cout << maxSum << "\n";

    return 0;
}
