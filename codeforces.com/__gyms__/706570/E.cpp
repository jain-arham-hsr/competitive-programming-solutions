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
        long long n, k;
        cin >> n >> k;

        long long totalSum = n * (2 * k + n - 1) / 2;
        long double b = 2.0 * k - 1.0;

        long long i = (-b + sqrtl(b * b + 4.0 * totalSum)) / 2.0;

        long long left1 = i * (2 * k + i - 1) / 2;
        long long ans = abs(totalSum - 2 * left1);

        if (i + 1 <= n) {
            long long left2 = (i + 1) * (2 * k + i) / 2;
            ans = min(ans, abs(totalSum - 2 * left2));
        }

        cout << ans << "\n";
    }
    return 0;
}
