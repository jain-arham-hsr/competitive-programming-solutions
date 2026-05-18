#include <bits/stdc++.h>
using namespace std;

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

    int maxL = 1;
    int minR = n;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        maxL = max(maxL, l);
        minR = min(minR, r);
    }

    vector<int> res(n, -1);

    int curr = 0;

    for (int i = maxL - 1; i < minR; i++) {
        res[i] = curr++;
    }

    cout << curr << "\n";

    for (int i = 0; i < n; i++) {
        if (res[i] == -1)
            res[i] = curr++;
    }

    for (auto &x : res)
        cout << x << " ";

    return 0;
}
