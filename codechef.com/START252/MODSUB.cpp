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
        vector<ll> nums(n);
        for (auto &x : nums)
            cin >> x;
        vector<ll> Q(n);
        Q[0] = nums[0];
        for (int i = 1; i < n; i++) {
            Q[i] = nums[i] - Q[i - 1];
        }
        vector<ll> suffMinEven(n + 1, LLONG_MAX);
        vector<ll> suffMinOdd(n + 1, LLONG_MAX);
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 0) {
                suffMinEven[i] = min(suffMinEven[i + 1], Q[i]);
                suffMinOdd[i] = suffMinOdd[i + 1];
            } else {
                suffMinOdd[i] = min(suffMinOdd[i + 1], Q[i]);
                suffMinEven[i] = suffMinEven[i + 1];
            }
        }
        int res = 0;
        ll d;
        for (int i = 0; i < n; i++) {
            if ((n - 1 - i) % 2 == 0)
                d = -Q[n - 1];
            else
                d = Q[n - 1];
            if (i % 2 == 0 && suffMinOdd[i] >= d && suffMinEven[i] >= -d) {
                res++;
            }
            if (i % 2 != 0 && suffMinEven[i] >= d && suffMinOdd[i] >= -d) {
                res++;
            }
            if (Q[i] < 0)
                break;
        }

        cout << res << "\n";
    }
    return 0;
}
