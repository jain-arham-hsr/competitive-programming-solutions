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

    ll n, k;
    cin >> n >> k;

    vector<ll> a(k);
    for (auto &x : a)
        cin >> x;

    ll res = 0;

    for (ll i = 1; i < (1LL << k); i++) {
        ll cnt = 0;
        ll prod = 1;
        ll numMultiples = 0;

        for (ll j = 0; j < k; j++) {
            ll bit = 1LL << j;
            if (((i & bit) > 0)) {
                if (((n / prod) + 1 >= a[j])) {
                    prod *= a[j];
                    cnt++;
                } else {
                    goto next_i;
                }
            }
        }
        numMultiples = n / prod;
        if (cnt % 2 == 0)
            res -= numMultiples;
        else
            res += numMultiples;

    next_i:;
    }

    cout << res << "\n";

    return 0;
}
