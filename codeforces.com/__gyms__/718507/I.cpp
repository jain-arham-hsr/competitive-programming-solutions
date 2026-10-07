#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;

ostream &operator<<(ostream &os, i128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9)
        os << (i128)(x / 10);
    return os << (int)(x % 10);
}

ostream &operator<<(ostream &os, u128 x) {
    if (x > 9)
        os << (u128)(x / 10);
    return os << (int)(x % 10);
}

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

int r = 0;
unordered_map<int, pair<int, int>> raw;

const int CAP = 100000000 + 1;

vector<int> findRawMaterialCount(vector<vector<int>> &dp,
                                 vector<vector<int>> &adjList, int itemId) {
    if (dp[itemId][0] != -1)
        return dp[itemId];
    vector<int> totalCnt(r);
    for (auto x : adjList[itemId]) {
        vector<int> currCnt = findRawMaterialCount(dp, adjList, x);
        for (int i = 0; i < r; i++) {
            totalCnt[i] += currCnt[i];
            if (totalCnt[i] > CAP)
                totalCnt[i] = CAP;
        }
    }
    return dp[itemId] = totalCnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(m + 1);
    vector<int> rawEle;

    for (int i = 1; i <= m; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int p;
            cin >> p;
            raw[i] = {p, raw.size()};
            rawEle.push_back(i);
        }

        for (int j = 0; j < c; j++) {
            int num;
            cin >> num;
            adjList[i].push_back(num);
        }
    }

    r = raw.size();

    vector<vector<int>> dp(m + 1, vector<int>(r, -1));

    for (auto x : raw) {
        for (int i = 0; i < r; i++) {
            dp[x.first][i] = 0;
        }
        dp[x.first][x.second.second] = 1;
    }

    for (int i = 1; i <= n; i++) {
        findRawMaterialCount(dp, adjList, i);
    }

    // watch(dp);

    int res = 0;

    for (int i = 1; i < (1 << n); i++) {
        vector<int> req(r);
        int curr = 0;
        for (int j = 0; j < n; j++) {
            int bit = (1 << j);
            if (bit & i) {
                curr++;
                for (int k = 0; k < r; k++) {
                    req[k] += dp[j + 1][k];
                }
            }
        }
        bool ok = true;
        for (int k = 0; k < r; k++) {
            if (raw[rawEle[k]].first < req[k])
                ok = false;
        }
        // watch(req);
        if (ok)
            res = max(res, curr);
    }

    cout << res << "\n";

    return 0;
}
