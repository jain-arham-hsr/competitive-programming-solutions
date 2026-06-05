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
    vector<int> nums(n);
    watch(nums);
    for (auto &x : nums)
        cin >> x;
    vector<vector<int>> adjList(n + 1);
    vector<int> groups(n + 1);
    vector<int> vst(n + 1);
    for (int i = 0; i < n + 1; i++) {
        groups[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (vst[i])
            continue;
        q.push(i);
        vst[i] = true;
        while (q.size()) {
            int curr = q.front();
            for (auto adj : adjList[curr]) {
                if (!vst[adj])
                    q.push(adj);
                groups[adj] = i;
                vst[adj] = true;
            }
            q.pop();
        }
    }

    watch(groups);

    map<int, int> minCost;

    for (int i = 0; i < n; i++) {
        if (minCost.count(groups[i + 1])) {
            minCost[groups[i + 1]] = min(minCost[groups[i + 1]], nums[i]);
        } else {
            minCost[groups[i + 1]] = nums[i];
        }
    }

    ll res = 0;

    for (auto it : minCost) {
        res += it.second;
    }

    cout << res << "\n";

    return 0;
}
