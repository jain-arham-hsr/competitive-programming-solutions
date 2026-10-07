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

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> x(q + 1);

    for (int i = 0; i < q; i++) {
        int l, r, val;
        cin >> l >> r >> val;

        x[val].push_back({l, r});
    }

    watch(x);

    vector<int> prefDiff(n + 1);

    for (int i = 0; i < q + 1; i++) {
        if (!x[i].size())
            continue;
        sort(x[i].begin(), x[i].end());
        pair<int, int> last = x[i][0];

        prefDiff[last.first - 1]++;
        prefDiff[last.second]--;
        for (auto p : x[i]) {
            if (p.first <= last.second) {
                prefDiff[last.second]++;
                prefDiff[max(last.second, p.second)]--;
                int temp = last.second;
                last = p;
                last.second = max(temp, p.second);
            } else {
                prefDiff[p.first - 1]++;
                prefDiff[p.second]--;
                last = p;
            }
        }
        watch(prefDiff);
    }

    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += prefDiff[i];
        cout << curr << " ";
    }

    return 0;
}
