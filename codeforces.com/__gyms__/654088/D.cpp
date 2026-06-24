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

long long prim(int n, vector<vector<pair<int, int>>> &adj) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    long long mstWeight = 0;
    int nodesUsed = 0;

    int maxWt = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        maxWt = max(maxWt, w);
        mstWeight += w;
        nodesUsed++;

        for (auto &[v, weight] : adj[u])
            if (!visited[v])
                pq.push({weight, v});
    }

    if (nodesUsed != n)
        return -1;
    return maxWt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> nodes(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        nodes[i].first = a;
        nodes[i].second = b;
    }

    vector<vector<pair<int, int>>> adjList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            int xDist = nodes[i].first - nodes[j].first;
            int yDist = nodes[i].second - nodes[j].second;
            adjList[i].push_back({j, xDist * xDist + yDist * yDist});
        }
    }

    cout << prim(n, adjList);

    return 0;
}
