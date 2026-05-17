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

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adjList[u].push_back({v, t});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    vector<long long> dst(n + 1, LONG_MAX);
    dst[1] = 0;
    int curr = 1;
    pq.push({0, 1});
    while (pq.size() > 0) {
        long long d = pq.top().first;
        curr = pq.top().second;
        pq.pop();

        if (d > dst[curr])
            continue;

        for (int i = 0; i < adjList[curr].size(); i++) {
            int next_node = adjList[curr][i].first;
            long long weight = adjList[curr][i].second;
            if (dst[curr] + weight < dst[next_node]) {
                dst[next_node] = dst[curr] + weight;
                pq.push({dst[next_node], next_node});
            }
        }
    }

    if (dst[n] == LONG_MAX) {
        cout << -1 << "\n";
    } else {
        cout << dst[n] << "\n";
    }

    return 0;
}
