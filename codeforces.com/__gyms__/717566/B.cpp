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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = '0' + s;
        vector<int> numChildren(n + 1);
        vector<int> childrenTrav(n + 1);
        vector<int> parent(n + 1);
        vector<char> sideOfParent(n + 1);

        queue<int> q;
        vector<int> dp(n + 1, -1);

        for (int i = 1; i < n + 1; i++) {
            int l, r;
            cin >> l >> r;
            parent[l] = i;
            sideOfParent[l] = 'L';
            parent[r] = i;
            sideOfParent[r] = 'R';
            numChildren[i] = (l != 0) + (r != 0);
            if (numChildren[i] == 0) {
                q.push(i);
                dp[i] = 0;
            }
        }

        watch(dp);

        while (q.size()) {
            int curr = q.front();
            q.pop();
            watch(curr, parent[curr], dp[parent[curr]]);
            if (dp[parent[curr]] == -1) {
                dp[parent[curr]] =
                    dp[curr] + (sideOfParent[curr] != s[parent[curr]]);
            } else {
                dp[parent[curr]] =
                    min(dp[parent[curr]],
                        dp[curr] + (sideOfParent[curr] != s[parent[curr]]));
            }
            watch(curr, parent[curr], dp[parent[curr]]);
            childrenTrav[parent[curr]]++;
            if (childrenTrav[parent[curr]] == numChildren[parent[curr]]) {
                q.push(parent[curr]);
            }
        }

        watch(dp);

        cout << dp[1] << "\n";
    }
    return 0;
}
