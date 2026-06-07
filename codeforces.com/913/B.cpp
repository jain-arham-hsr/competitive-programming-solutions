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

    vector<int> parents(n - 1);
    for (auto &x : parents)
        cin >> x;

    vector<int> numChildren(n + 1);
    for (int i = 0; i < n - 1; i++) {
        numChildren[parents[i]]++;
    }

    vector<int> leafChildren(n + 1);

    for (int i = 0; i < n - 1; i++) {
        if (numChildren[i + 2] == 0) {
            leafChildren[parents[i]]++;
        }
    }

    int ok = true;
    for (int i = 1; i <= n; i++) {
        if (numChildren[i] != 0 && leafChildren[i] < 3) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";

    return 0;
}
