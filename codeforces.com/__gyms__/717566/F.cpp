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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;

        vector<vector<int>> adjList(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        queue<pair<int, int>> q;
        q.push({s, 0});

        vector<int> vst(n + 1);

        int minDist = 0;

        while (q.size()) {
            pair<int, int> curr = q.front();
            if (curr.first == t) {
                minDist = curr.second;
                break;
            }
            q.pop();
            for (auto adj : adjList[curr.first]) {
                if (!vst[adj]) {
                    q.push({adj, curr.second + 1});
                    vst[adj] = true;
                }
            }
        }

        vector<int> dp(n + 1, -1);
        for (auto adj : adjList[s]) {
            dp[adj] = 1;
        }
        queue<pair<int, int>> q2;
        q2.push({s, 0});

        int res = 0;

        while (q2.size()) {
            pair<int, int> curr = q2.front();
            if (curr.first == t) {
                res++;
            }
            q2.pop();
            for (auto adj : adjList[curr.first]) {
                if (curr.second + 1 > minDist + 1)
                    break;
                q2.push({adj, curr.second + 1});
            }
        }

        watch(minDist);
        cout << res << "\n";
    }
    return 0;
}
