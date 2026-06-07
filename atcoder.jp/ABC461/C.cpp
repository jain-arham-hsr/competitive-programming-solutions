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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    vector<pair<int, int>> gems(n);

    for (int i = 0; i < n; i++) {
        int c, v;
        cin >> c >> v;
        gems.push_back({v, c});
    }
    sort(gems.rbegin(), gems.rend());

    map<int, bool> inc;
    vector<bool> used(n);

    long long res = 0;

    watch(gems);
    for (int i = 0; i < n; i++) {
        if (used[i] || (inc[gems[i].second] && m > 0))
            continue;
        res += gems[i].first;
        used[i] = true;
        inc[gems[i].second] = true;
        m--;
        k--;
        if (m == 0)
            i = 0;
        if (k == 0)
            break;
    }

    cout << res << "\n";

    return 0;
}
