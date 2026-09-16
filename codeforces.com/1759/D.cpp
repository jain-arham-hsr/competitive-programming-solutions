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

    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        ll nTrimmed = n;
        while (nTrimmed % 10 == 0)
            nTrimmed /= 10;
        long long a = pow(10, int(log10(m)));
        int firstDig = m / a;
        if (nTrimmed % 5 == 0) {
            if (firstDig >= 2) {
                cout << n * (firstDig - (firstDig % 2)) * a << " 2\n";
                continue;
            } else if (a > 1 && (m - firstDig * a) / (a / 10) >= 2) {
                watch(firstDig, a);
                int secondDig = (m - firstDig * a) / (a / 10);
                cout << n * (firstDig * a +
                             (secondDig - (secondDig % 2)) * (a / 10))
                     << " 3\n";
                continue;
            }
            cout << n * max(1, (firstDig - (firstDig % 2))) * a << " 1\n";
            continue;
        } else if (nTrimmed % 2 == 0) {
            if (firstDig >= 5) {
                cout << n * 5 * a << " 2\n";
                continue;
            } else if (a > 1 && (m - firstDig * a) / (a / 10) >= 5) {
                watch(firstDig, a);
                cout << n * (firstDig * a + 5 * (a / 10)) << " 3\n";
                continue;
            }
        }
        cout << n * firstDig * a << " 4\n";
    }
    return 0;
}
