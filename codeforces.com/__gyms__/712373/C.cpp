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

        vector<pair<int, int>> edges;
        edges.reserve(n - 1);

        vector<vector<int>> adjList(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            edges.push_back({a, b});
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        bool valid = true;

        for (int i = 0; i < n; i++) {
            if (adjList[i].size() > 2) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "-1\n";
            continue;
        }

        vector<pair<int, int>> t(n);

        int start = -1;

        for (int i = 0; i < n; i++) {
            if (adjList[i].size() == 1) {
                start = i;
            }
        }

        watch(adjList);

        vector<bool> vst(n);
        int curr = start;
        for (int i = 0; i < n - 1; i++) {
            watch(curr);
            int next = adjList[curr][0];
            if (vst[next])
                next = adjList[curr][1];
            watch(next);
            t[curr].first = next;
            t[curr].second = i % 2 == 0 ? 2 : 3;
            vst[curr] = true;
            watch(next);
            curr = next;
        }
        watch(t);
        watch(curr);

        for (int i = 0; i < n - 1; i++) {
            watch(edges[i]);
            if (t[edges[i].first].first == edges[i].second &&
                edges[i].first != curr) {
                cout << t[edges[i].first].second << " ";
            } else {
                cout << t[edges[i].second].second << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
