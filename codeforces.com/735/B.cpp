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

    int n, n1, n2;
    cin >> n >> n1 >> n2;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;
    sort(nums.begin(), nums.end());
    if (n2 < n1)
        swap(n1, n2);
    long double sum1 = 0;
    long double sum2 = 0;
    for (int i = 0; i < n1; i++) {
        sum1 += nums[n - 1 - i];
    }
    for (int i = 0; i < n2; i++) {
        sum2 += nums[n - 1 - n1 - i];
    }
    cout << fixed << setprecision(8) << (sum1 / n1 + sum2 / n2);

    return 0;
}
