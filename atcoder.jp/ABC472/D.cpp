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

bool canUpdate(vector<vector<int>> &mat, int x, int y, int k, int newVal) {
    return x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() &&
           mat[x][y] != 1 && mat[x][y] > newVal && newVal <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, k;
    cin >> h >> w >> k;

    vector<string> rows(h);
    for (auto &x : rows)
        cin >> x;

    vector<bool> emptyRows(h, true);
    vector<bool> emptyCols(w, true);

    vector<vector<int>> mat(h, vector<int>(w, INT_MAX));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (rows[i][j] == '#') {
                emptyRows[i] = false;
                emptyCols[j] = false;
                mat[i][j] = -1;
            }
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (emptyRows[i] && emptyCols[j]) {
                mat[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        int newVal = mat[x][y] + 1;
        if (canUpdate(mat, x + 1, y, k, newVal)) {
            mat[x + 1][y] = newVal;
            q.push({x + 1, y});
        }
        if (canUpdate(mat, x - 1, y, k, newVal)) {
            mat[x - 1][y] = newVal;
            q.push({x - 1, y});
        }
        if (canUpdate(mat, x, y + 1, k, newVal)) {
            mat[x][y + 1] = newVal;
            q.push({x, y + 1});
        }
        if (canUpdate(mat, x, y - 1, k, newVal)) {
            mat[x][y - 1] = newVal;
            q.push({x, y - 1});
        }
    }

    int res = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mat[i][j] > -1 && mat[i][j] != INT_MAX) {
                res++;
            }
        }
    }

    cout << res;
}
