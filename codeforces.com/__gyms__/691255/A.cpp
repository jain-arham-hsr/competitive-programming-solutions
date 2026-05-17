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

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (auto &row : mat) {
        for (auto &cell : row) {
            cin >> cell;
        }
    }
    vector<vector<pair<int, int>>> pows(n, vector<pair<int, int>>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int twos = 0;
            int fives = 0;
            int k = mat[i][j];
            while (k % 2 == 0) {
                twos++;
                k /= 2;
            }
            while (k % 5 == 0) {
                fives++;
                k /= 5;
            }
            pows[i][j] = {twos, fives};
        }
    }
    vector<vector<pair<string, pair<int, int>>>> dp(
        n, vector<pair<string, pair<int, int>>>(n));

    dp[0][0] = {"", pows[0][0]};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair<string, pair<int, int>> top, left;
            pair<int, int> curr = pows[i][j];
            if (i > 0)
                top = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            // if (i > 0)
            //     sumTop = min(dp[i - 1][j].second.first + pows[i][j].first,
            //                  dp[i - 1][j].second.second + pows[i][j].second);
            // if (j > 0)
            //     sumLeft = min(dp[i][j - 1].second.first + pows[i][j].first,
            //                   dp[i][j - 1].second.second +
            //                   pows[i][j].second);
            if (i > 0 && j > 0) {
                if (min(top.second.first + curr.first,
                        top.second.second + curr.second) <
                    min(left.second.first + curr.first,
                        left.second.second + curr.second)) {
                    dp[i][j] = {top.first + "D",
                                {top.second.first + curr.first,
                                 top.second.second + curr.second}};
                } else if (min(top.second.first + curr.first,
                               top.second.second + curr.second) >
                           min(left.second.first + curr.first,
                               left.second.second + curr.second)) {
                    dp[i][j] = {left.first + "R",
                                {left.second.first + curr.first,
                                 left.second.second + curr.second}};
                } else {
                    if (top.second.first + top.second.second >
                        left.second.first + left.second.second) {
                        dp[i][j] = {left.first + "R",
                                    {left.second.first + curr.first,
                                     left.second.second + curr.second}};
                    } else {
                        dp[i][j] = {top.first + "D",
                                    {top.second.first + curr.first,
                                     top.second.second + curr.second}};
                    }
                }
            } else if (j > 0) {
                dp[i][j] = {left.first + "R",
                            {left.second.first + curr.first,
                             left.second.second + curr.second}};
            } else if (i > 0) {
                dp[i][j] = {top.first + "D",
                            {top.second.first + curr.first,
                             top.second.second + curr.second}};
            }
        }
    }
    // watch(dp[n - 1][n - 1]);
    cout << min(dp[n - 1][n - 1].second.first, dp[n - 1][n - 1].second.second)
         << "\n"
         << dp[n - 1][n - 1].first;

    return 0;
}
