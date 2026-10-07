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

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; (long long)i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;

    return isPrime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<bool> isPrime = sieve(1e7 + 1);

    vector<int> valid(1e6 + 1);

    for (int i = 0; i < 1e6 + 1; i++) {
        string str = to_string(i);
        int new_int = 0;
        for (int j = 0; j < str.size(); j++) {
            new_int += (str[j] - '0') * (pow(10, j));
        }
        if (isPrime[new_int] && isPrime[i]) {
            valid[i] = true;
        }
    }

    vector<int> validPrefSum(1e6 + 1);

    partial_sum(valid.begin(), valid.end(), validPrefSum.begin());

    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;

        if (l == 0)
            cout << validPrefSum[l] << "\n";
        else
            cout << validPrefSum[r] - validPrefSum[l - 1] << "\n";
    }
    return 0;
}
