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

struct DSU {
  private:
    vector<int> parent, rank_, size_, edgeCount_;

  public:
    DSU(int n) : parent(n), rank_(n, 0), size_(n, 1), edgeCount_(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        edgeCount_[x]++;
        if (x == y)
            return false;
        if (rank_[x] < rank_[y])
            swap(x, y);
        parent[y] = x;
        size_[x] += size_[y];
        edgeCount_[x] += edgeCount_[y];
        if (rank_[x] == rank_[y])
            rank_[x]++;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
    int size(int x) { return size_[find(x)]; }
    int edgeCount(int x) { return edgeCount_[find(x)]; }
    int components(int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == i)
                cnt++;
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }

    for (int i = 1; i <= n; i++) {
        ll k = dsu.size(i);
        // watch(dsu.find(i));
        // watch(k, dsu.edgeCount(i));
        if (k * (k - 1) / 2 != dsu.edgeCount(i)) {
            // watch(i, k, dsu.edgeCount(i));
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
