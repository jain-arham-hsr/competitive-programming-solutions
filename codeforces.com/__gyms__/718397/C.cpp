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

ll MOD = 1000000007;

ll comb(ll curr, ll bit) {
    ll temp = 0;
    for (ll i = 1; i <= curr; i++) {
        temp = (temp + bit * ((i * (curr - i + 1)) % MOD)) % MOD;
    }
    return temp % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (auto &x : nums)
        cin >> x;

    ll res = 0;

    for (ll j = 0; j < 31; j++) {
        ll curr = 0;
        ll bit = 1LL << j;
        for (int i = 0; i < n; i++) {
            if (nums[i] & bit)
                curr++;
            else {
                res = (res + comb(curr, bit)) % MOD;
                curr = 0;
            }
        }
        res = (res + comb(curr, bit)) % MOD;
    }

    cout << res << "\n";

    return 0;
}
