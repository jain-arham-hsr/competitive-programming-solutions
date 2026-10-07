#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;

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

    int r, c;
    cin >> r >> c;

    vector<string> grid(r);
    for (auto &x : grid)
        cin >> x;

    vector<pair<int, int>> land;
    land.reserve(3);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '#')
                land.push_back({i, j});
        }
    }

    int minCost = r * c;
    pair<int, int> minMeet = {0, 0};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int cost = -2;
            for (int k = 0; k < 3; k++) {
                cost += abs(land[k].first - i) + abs(land[k].second - j);
            }
            watch(cost);
            if (cost < minCost) {
                minCost = cost;
                minMeet = {i, j};
            }
        }
    }

    int minX = min(minMeet.first,
                   min(land[0].first, min(land[1].first, land[2].first)));
    int maxX = max(minMeet.first,
                   max(land[0].first, max(land[1].first, land[2].first)));

    for (int i = minX; i <= maxX; i++) {
        grid[i][minMeet.second] = '#';
    }

    for (auto x : land) {
        for (int i = min(x.second, minMeet.second);
             i <= max(x.second, minMeet.second); i++) {
            grid[x.first][i] = '#';
        }
    }

    for (auto &x : grid)
        cout << x << "\n";

    return 0;
}
