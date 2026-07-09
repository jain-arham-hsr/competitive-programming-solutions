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

    int n;
    cin >> n;

    map<int, bool> exists;
    map<int, int> pairs;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pairs[a] = b;
        exists[b] = true;
    }

    vector<int> queue(n + 2);

    queue[0] = 0;

    for (auto x : pairs) {
        if (!exists[x.first])
            queue[1] = x.first;
    }

    for (int i = 2; i < n + 2; i++) {
        queue[i] = pairs[queue[i - 2]];
    }

    for (int i = 1; i <= n; i++)
        cout << queue[i] << " ";

    return 0;
}
