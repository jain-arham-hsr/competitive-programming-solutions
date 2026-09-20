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
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);

        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        vector<ll> maxL_A(n);
        vector<ll> maxR_A(n);

        vector<ll> maxL_B(n);
        vector<ll> maxR_B(n);

        ll currVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            currVal = max(a[i], currVal + a[i]);
            maxL_A[i] = currVal;
        }

        currVal = 0;
        for (int i = 0; i < n; i++) {
            currVal = max(b[i], currVal + b[i]);
            maxL_B[i] = currVal;
        }

        currVal = 0;
        for (int i = n - 1; i >= 0; i--) {
            currVal = max(a[i], currVal + a[i]);
            maxR_A[i] = currVal;
        }

        currVal = 0;
        for (int i = n - 1; i >= 0; i--) {
            currVal = max(b[i], currVal + b[i]);
            maxR_B[i] = currVal;
        }

        ll res = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            res = max(res, maxL_A[i] + maxR_A[i] - a[i] + maxL_B[i] +
                               maxR_B[i] - b[i]);
        }

        cout << res << "\n";
    }
    return 0;
}
