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
        int n, k;
        cin >> n >> k;

        vector<vector<int>> adjList(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        queue<int> q;
        vector<int> degree(n + 1);

        for (int i = 1; i <= n; i++) {
            degree[i] = adjList[i].size();
            if (degree[i] <= 1) {
                q.push(i);
            }
        }

        q.push(-1);

        int rem = 0;

        vector<int> vst(n + 1);

        int lvl = 0;

        while (q.size()) {
            int curr = q.front();
            if (curr == -1) {
                lvl++;
                if (rem == n || lvl == k)
                    break;
                q.push(-1);
            } else {
                for (int val : adjList[curr]) {
                    degree[val]--;
                    if (!vst[val] && degree[val] == 1) {
                        q.push(val);
                        vst[curr] = true;
                    }
                }
                rem++;
            }
            q.pop();
        }

        cout << n - rem << "\n";
    }
    return 0;
}
