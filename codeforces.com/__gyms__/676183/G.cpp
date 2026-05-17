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

    long long n, budget;
    cin >> n >> budget;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    vector<long long> b(n);
    for (auto &x : b)
        cin >> x;
    long long l = -1, r = n + 1;
    // long long minCost = 0;
    while (l < r - 1) {
        long long mid = l + (r - l) / 2;
        vector<long long> costs(n);
        for (int i = 0; i < n; i++) {
            costs[i] = (long long)a[i] + mid * b[i];
        }
        sort(costs.begin(), costs.end());
        long long cost = 0;
        for (int i = 0; i < mid; i++) {
            cost += costs[i];
        }
        if (cost <= budget) {
            // minCost = cost;
            l = mid;
        } else {
            r = mid;
        }
    }

    vector<long long> costs(n);
    for (int i = 0; i < n; i++) {
        costs[i] = (long long)a[i] + l * b[i];
    }
    sort(costs.begin(), costs.end());
    long long cost = 0;
    for (int i = 0; i < l; i++) {
        cost += costs[i];
    }

    cout << l << " " << cost;
    return 0;
}
