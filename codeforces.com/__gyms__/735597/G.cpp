#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ostream &operator<<(ostream &os, i128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9)
        os << (i128)(x / 10);
    return os << (int)(x % 10);
}

ostream &operator<<(ostream &os, u128 x) {
    if (x > 9)
        os << (u128)(x / 10);
    return os << (int)(x % 10);
}

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
ostream &operator<<(ostream &os, const T &c);

template <typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &t) {
    os << "(";
    apply(
        [&](auto &...x) {
            bool f = true;
            ((os << (f ? f = false, "" : ", ") << x), ...);
        },
        t);
    return os << ")";
}

template <typename T>
auto operator<<(ostream &os, const T &x) -> decltype(x._fields(), os) {
    return os << x._fields();
}

template <typename T, typename C>
ostream &operator<<(ostream &os, stack<T, C> s) {
    vector<T> v;
    for (; !s.empty(); s.pop())
        v.push_back(s.top());
    reverse(all(v));
    return os << v;
}

template <typename T, typename C>
ostream &operator<<(ostream &os, queue<T, C> q) {
    os << "{";
    for (bool f = true; !q.empty(); q.pop())
        os << (f ? f = false, "" : ", ") << q.front();
    return os << "}";
}

template <typename T, typename C, typename Cmp>
ostream &operator<<(ostream &os, priority_queue<T, C, Cmp> pq) {
    os << "{";
    for (bool f = true; !pq.empty(); pq.pop())
        os << (f ? f = false, "" : ", ") << pq.top();
    return os << "}";
}

template <typename T, typename> ostream &operator<<(ostream &os, const T &c) {
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

#define FIELDS(...)                                                            \
    auto _fields() const { return tie(__VA_ARGS__); }                          \
    template <typename O> bool operator<(const O &o) const {                   \
        return _fields() < o._fields();                                        \
    }                                                                          \
    template <typename O> bool operator>(const O &o) const {                   \
        return _fields() > o._fields();                                        \
    }                                                                          \
    template <typename O> bool operator==(const O &o) const {                  \
        return _fields() == o._fields();                                       \
    }                                                                          \
    template <typename O> bool operator!=(const O &o) const {                  \
        return _fields() != o._fields();                                       \
    }

// ==================================================================== //

struct mirr_count {
    int cnt;
    int exit_x;
    int exit_y;
};

void clear_vst(vector<vector<bool>> &vst) {
    for (int i = 0; i < vst.size(); i++) {
        for (int j = 0; j < vst[0].size(); j++) {
            vst[i][j] = 0;
        }
    }
}

mirr_count mirror_count(int st_x, int st_y, int r, int c, char st_dir,
                        vector<string> &grid, vector<vector<bool>> &vst) {
    int x = st_x, y = st_y;
    char curr_dir = st_dir;
    int cnt = 0;
    map<int, pair<int, int>> dir = {
        {'R', {1, 0}},
        {'L', {-1, 0}},
        {'U', {0, -1}},
        {'D', {0, 1}},
    };
    map<char, char> fwd_mirr_op = {
        {'R', 'U'}, {'L', 'D'}, {'U', 'R'}, {'D', 'L'}};
    map<char, char> bwd_mirr_op = {
        {'R', 'D'}, {'L', 'U'}, {'U', 'L'}, {'D', 'R'}};

    clear_vst(vst);
    while (x >= 0 && x < c && y >= 0 && y < r) {
        if (grid[y][x] == '/') {
            if (!vst[y][x])
                cnt++;
            curr_dir = fwd_mirr_op[curr_dir];
        } else if (grid[y][x] == '\\') {
            if (!vst[y][x])
                cnt++;
            curr_dir = bwd_mirr_op[curr_dir];
        }
        vst[y][x] = true;
        x += dir[curr_dir].first;
        y += dir[curr_dir].second;
    }
    return {cnt, x, y};
}

void mark_exit(vector<int> &north, vector<int> &south, vector<int> &east,
               vector<int> &west, int exit_x, int exit_y, int r, int c,
               bool equal) {
    if (exit_x < 0) {
        west[exit_y] = equal;
    } else if (exit_x >= c) {
        east[exit_y] = equal;
    } else if (exit_y < 0) {
        north[exit_x] = equal;
    } else if (exit_y >= r) {
        south[exit_x] = equal;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll r, c;
    cin >> r >> c;

    vector<string> grid(r);
    for (auto &x : grid)
        cin >> x;

    int total_mirrors = 0;

    for (int i = 0; i < r; i++) {
        total_mirrors += count(all(grid[i]), '/');
        total_mirrors += count(all(grid[i]), '\\');
    }

    vector<int> north(c, -1);
    vector<int> south(c, -1);
    vector<int> east(r, -1);
    vector<int> west(r, -1);

    vector<vector<bool>> vst(r, vector<bool>(c));

    for (int i = 0; i < c; i++) {
        if (north[i] < 0) {
            mirr_count n = mirror_count(i, 0, r, c, 'D', grid, vst);
            bool equal = n.cnt == total_mirrors;
            north[i] = equal;
            mark_exit(north, south, east, west, n.exit_x, n.exit_y, r, c,
                      equal);
        }
        if (south[i] < 0) {
            mirr_count s = mirror_count(i, r - 1, r, c, 'U', grid, vst);
            bool equal = s.cnt == total_mirrors;
            south[i] = equal;
            mark_exit(north, south, east, west, s.exit_x, s.exit_y, r, c,
                      equal);
        }
    }

    for (int i = 0; i < r; i++) {
        if (west[i] < 0) {
            mirr_count w = mirror_count(0, i, r, c, 'R', grid, vst);
            bool equal = w.cnt == total_mirrors;
            west[i] = equal;
            mark_exit(north, south, east, west, w.exit_x, w.exit_y, r, c,
                      equal);
        }
        if (east[i] < 0) {
            mirr_count et = mirror_count(c - 1, i, r, c, 'L', grid, vst);
            bool equal = et.cnt == total_mirrors;
            east[i] = equal;
            mark_exit(north, south, east, west, et.exit_x, et.exit_y, r, c,
                      equal);
        }
    }

    vector<string> res;
    for (int i = 0; i < c; i++) {
        if (north[i]) {
            res.push_back("N" + to_string(i + 1));
        }
        if (south[i]) {
            res.push_back("S" + to_string(i + 1));
        }
    }
    for (int i = 0; i < r; i++) {
        if (east[i]) {
            res.push_back("E" + to_string(i + 1));
        }
        if (west[i]) {
            res.push_back("W" + to_string(i + 1));
        }
    }

    cout << res.size() << "\n";
    for (auto &x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}
