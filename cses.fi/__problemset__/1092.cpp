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

    long long n;
    cin >> n;

    if (n % 4 != 0 && (n + 1) % 4 != 0) {
        cout << "NO\n";
        return 0;
    }

    vector<int> a;
    vector<int> b;

    long long s = n * (n + 1) / 4;

    for (int i = n; i > 0; i--) {
        if (i <= s) {
            a.push_back(i);
            s -= i;
        } else {
            b.push_back(i);
        }
    }

    cout << "YES\n";
    cout << a.size() << "\n";
    for (auto &x : a)
        cout << x << " ";
    cout << "\n";
    cout << b.size() << "\n";
    for (auto &x : b)
        cout << x << " ";

    return 0;
}
