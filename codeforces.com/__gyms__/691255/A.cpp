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

pair<pair<int, char>, pair<int, char>> dp[1001][1001];

pair<pair<int, char>, pair<int, char>>
findLeastTwoFive(vector<vector<int>> &grid, int x, int y) {

    if (dp[x][y].first.first != -1)
        return dp[x][y];

    int val = grid[y][x];
    int twoPower = 0, fivePower = 0;
    if (val == 0) {
        twoPower = 1;
        fivePower = 1;
    } else {
        while (val % 2 == 0) {
            val /= 2;
            twoPower++;
        }
        while (val % 5 == 0) {
            val /= 5;
            fivePower++;
        }
    }

    if (x == grid.size() - 1 && y == grid.size() - 1) {
        watch(y, x, twoPower, fivePower);
        return dp[x][y] = {{twoPower, 0}, {fivePower, 0}};
    }

    pair<int, char> two = {1e9, 0};
    pair<int, char> five = {1e9, 0};

    if (x < grid.size() - 1) {
        auto [twoR, fiveR] = findLeastTwoFive(grid, x + 1, y);
        two = {twoR.first, 'R'};
        five = {fiveR.first, 'R'};
    }
    if (y < grid.size() - 1) {
        auto [twoD, fiveD] = findLeastTwoFive(grid, x, y + 1);
        if (twoD.first < two.first) {
            two = {twoD.first, 'D'};
        }
        if (fiveD.first < five.first) {
            five = {fiveD.first, 'D'};
        }
    }

    two.first += twoPower;
    five.first += fivePower;
    watch(y, x, two, five);
    return dp[x][y] = {two, five};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    fill((pair<pair<int, char>, pair<int, char>> *)begin(dp),
         (pair<pair<int, char>, pair<int, char>> *)end(dp),
         pair<pair<int, char>, pair<int, char>>{{-1, 0}, {-1, 0}});

    bool zeroExists = false;
    int zeroX = -1;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            grid[i][j] = num;
            if (num == 0) {
                zeroExists = true;
                zeroX = j;
            }
        }
    }

    auto [two, five] = findLeastTwoFive(grid, 0, 0);

    watch(two, five);

    if (!zeroExists || min(two.first, five.first) < 1) {
        bool useTwo = two.first <= five.first;
        cout << (useTwo ? two.first : five.first) << "\n";

        int curX = 0, curY = 0;
        string path = "";
        while (curX != n - 1 || curY != n - 1) {
            char move = useTwo ? dp[curX][curY].first.second
                               : dp[curX][curY].second.second;
            path += move;
            if (move == 'R')
                curX++;
            else
                curY++;
        }
        cout << path << "\n";
    } else {
        cout << 1 << "\n";
        string a(zeroX, 'R');
        string b(n - 1, 'D');
        string c(n - 1 - zeroX, 'R');
        cout << a + b + c;
    }

    return 0;
}
