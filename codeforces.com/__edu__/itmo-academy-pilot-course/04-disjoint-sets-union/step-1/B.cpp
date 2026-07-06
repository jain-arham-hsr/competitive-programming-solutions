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
    vector<int> parent, rank_, size_, minval_, maxval_;

  public:
    DSU(int n) : parent(n), rank_(n, 0), size_(n, 1), minval_(n), maxval_(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            minval_[i] = i;
            maxval_[i] = i;
        }
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (rank_[x] < rank_[y])
            swap(x, y);
        parent[y] = x;
        size_[x] += size_[y];
        minval_[x] = min(minval_[x], minval_[y]);
        maxval_[x] = max(maxval_[x], maxval_[y]);
        if (rank_[x] == rank_[y])
            rank_[x]++;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
    int size(int x) { return size_[find(x)]; }
    int minval(int x) { return minval_[find(x)]; }
    int maxval(int x) { return maxval_[find(x)]; }
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
        string qtype;
        cin >> qtype;
        if (qtype == "union") {
            int a, b;
            cin >> a >> b;
            dsu.unite(a, b);
        } else {
            int p;
            cin >> p;
            cout << dsu.minval(p) << " " << dsu.maxval(p) << " " << dsu.size(p)
                 << "\n";
        }
    }
    return 0;
}
