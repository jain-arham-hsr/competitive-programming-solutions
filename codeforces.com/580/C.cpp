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

    int n, m;
    cin >> n >> m;
    vector<bool> catExists(n + 1);
    for (int i = 1; i <= n; i++) {
        bool exists;
        cin >> exists;
        catExists[i] = exists;
    }

    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    vector<int> numCats(n + 1);

    if (catExists[1])
        numCats[1] = 1;

    int res = 0;

    vector<int> vst(n + 1);

    while (q.size()) {
        int vert = q.front();
        vst[vert] = true;
        bool isLeaf = true;
        for (auto vert2 : adjList[vert]) {
            if (!vst[vert2]) {
                q.push(vert2);
                if (catExists[vert2] || numCats[vert] > m)
                    numCats[vert2] = numCats[vert] + catExists[vert2];
                isLeaf = false;
            }
        }
        if (isLeaf && numCats[vert] <= m)
            res++;
        q.pop();
    }

    cout << res;

    return 0;
}
