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

    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for (auto &x : adj) {
    //     for (auto &y : x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    vector<int> dst(n + 1, -1);

    queue<int> q;

    q.push(s);
    dst[s] = 0;

    while (q.size() > 0) {
        int curr = q.front();
        for (int i = 1; i <= n; i++) {
            if (find(adj[curr].begin(), adj[curr].end(), i) ==
                    adj[curr].end() &&
                dst[i] == -1) {
                dst[i] = dst[curr] + 1;
                q.push(i);
            }
        }
        q.pop();
    }

    for (int i = 1; i <= n; i++) {
        if (i == s)
            continue;
        cout << dst[i] << " ";
    }

    return 0;
}
