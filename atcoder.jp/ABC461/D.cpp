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

    int h, w, k;
    cin >> h >> w >> k;

    vector<string> grid(h);
    for (auto &x : grid)
        cin >> x;

    watch(grid);

    vector<vector<int>> partSum(h + 1, vector<int>(w + 1, 0));

    for (int i = 0; i < h; i++) {
        int currSum = 0;
        for (int j = 0; j < w; j++) {
            currSum += grid[i][j] - '0';
            partSum[i + 1][j + 1] = currSum;
        }
    }

    watch(partSum);

    for (int j = 0; j <= w; j++) {
        int currSum = 0;
        for (int i = 0; i <= h; i++) {
            currSum += partSum[i][j];
            partSum[i][j] = currSum;
        }
    }

    watch(partSum);

    long long res = 0;

    vector<int> freq(2500001);
    for (int c1 = 0; c1 < h; c1++) {
        for (int c2 = c1 + 1; c2 <= h; c2++) {
            for (int i = 0; i <= w; i++) {
                if (partSum[c2][i] - partSum[c1][i] >= k)
                    res += freq[partSum[c2][i] - partSum[c1][i] - k];
                freq[partSum[c2][i] - partSum[c1][i]]++;
            }

            for (int i = 0; i <= w; i++) {
                int current_sum = partSum[c2][i] - partSum[c1][i];
                freq[current_sum]--;
            }
        }
    }

    cout << res;

    return 0;
}
