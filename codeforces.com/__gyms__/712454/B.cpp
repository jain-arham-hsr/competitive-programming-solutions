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
    vector<int> parent, rank_, size_;

  public:
    DSU(int n) : parent(n), rank_(n, 0), size_(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
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
        if (rank_[x] == rank_[y])
            rank_[x]++;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
    int size(int x) { return size_[find(x)]; }
    int components(int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == i)
                cnt++;
        return cnt;
    }
};

int getEle(int x, int y, int z, int i, int j, int k) {
    return k * x * y + i * y + j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;

        int total = x * y * z;

        vector<vector<string>> grid;
        grid.reserve(z);

        DSU dsu(total);
        for (int k = 0; k < z; k++) {
            vector<string> face;
            face.reserve(x);
            for (int i = 0; i < x; i++) {
                string row;
                cin >> row;
                face.push_back(row);
                for (int j = 0; j < y; j++) {
                    if (j > 0) {
                        if (row[j] == row[j - 1])
                            dsu.unite(getEle(x, y, z, i, j, k),
                                      getEle(x, y, z, i, j - 1, k));
                    }
                    if (i > 0) {
                        if (face[i - 1][j] == row[j])
                            dsu.unite(getEle(x, y, z, i, j, k),
                                      getEle(x, y, z, i - 1, j, k));
                    }
                    if (k > 0) {
                        if (grid[k - 1][i][j] == face[i][j])
                            dsu.unite(getEle(x, y, z, i, j, k),
                                      getEle(x, y, z, i, j, k - 1));
                    }
                    watch(dsu.size(getEle(x, y, z, i, j, k)));
                }
            }
            grid.push_back(face);
        }

        watch(dsu.size(3));

        int res = 0;

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                vector<bool> incl(x * y * z);
                int curr = 0;
                for (int k = 0; k < z; k++) {
                    int ind = getEle(x, y, z, i, j, k);
                    // watch(i, j, k, dsu.size(ind));
                    if (grid[k][i][j] == '.') {
                        watch(ind, dsu.size(ind));
                        watch(incl[dsu.find(ind)]);
                    }
                    if (grid[k][i][j] == '.' && !incl[dsu.find(ind)]) {
                        curr += dsu.size(ind);
                        incl[dsu.find(ind)] = true;
                    }
                }
                watch(curr);
                res = max(res, curr);
            }
        }

        cout << res << "\n";
    }
    return 0;
}
