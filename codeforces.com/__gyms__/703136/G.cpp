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

vector<string> a;
vector<string> b;

struct DSU {
  private:
    vector<int> parent, rank_, size_, diff_;

  public:
    DSU(int n, int rowSize) : parent(n), rank_(n, 0), size_(n, 1), diff_(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            int p = i / rowSize;
            int q = i % rowSize;
            diff_[i] = a[p][q] != b[p][q];
        }
        watch(diff_);
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
        diff_[x] += diff_[y];
        if (rank_[x] == rank_[y])
            rank_[x]++;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
    int size(int x) { return size_[find(x)]; }
    int diff(int x) { return diff_[find(x)]; }
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

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        a.push_back(row);
    }
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        b.push_back(row);
    }

    watch(a);
    watch(b);

    DSU dsu(n * m, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) {
                if (a[i][j] == a[i - 1][j])
                    dsu.unite(i * m + j, (i - 1) * m + j);
            }
            if (i < n - 1) {
                if (a[i][j] == a[i + 1][j])
                    dsu.unite(i * m + j, (i + 1) * m + j);
            }
            if (j > 0) {
                if (a[i][j] == a[i][j - 1])
                    dsu.unite(i * m + j, i * m + j - 1);
            }
            if (j < n - 1) {
                if (a[i][j] == a[i][j + 1])
                    dsu.unite(i * m + j, i * m + j + 1);
            }
        }
    }

    long long res = 0;
    vector<bool> reprIncl(n * m);
    for (int i = 0; i < n * m; i++) {
        int repr = dsu.find(i);
        if (!reprIncl[repr]) {
            res += min(dsu.size(repr) - dsu.diff(repr), dsu.diff(repr));
            reprIncl[repr] = true;
        }
    }

    cout << res << "\n";

    return 0;
}
