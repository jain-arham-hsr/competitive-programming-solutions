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

vector<int> findMaxIncSub(vector<int> &a) {
    int n = a.size();
    vector<int> curr(n);
    curr[0] = a[0];
    watch(a);

    vector<int> maxInc(n);

    int last = -1;
    if (curr[0] < 0) {
        maxInc[0] = curr[0];
        last = 0;
    }
    watch(last);

    for (int i = 1; i < n; i++) {
        curr[i] = max(curr[i - 1] + a[i], a[i]);
        watch(curr);
        if (curr[i] < 0 || i == n - 1) {
            int suffMax = curr[i];
            for (int j = i; j > last; j--) {
                suffMax = max(suffMax, curr[j]);
                maxInc[j] = suffMax;
                watch(maxInc);
            }
            last = i;
        }
        watch(maxInc);
    }
    return maxInc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<int> b(n);
        for (auto &x : b)
            cin >> x;

        vector<int> maxIncA = findMaxIncSub(a);
        vector<int> maxIncB = findMaxIncSub(b);

        watch(maxIncA);
        watch(maxIncB);

        int res = maxIncA[0] + maxIncB[0];
        for (int i = 1; i < n; i++) {
            res = max(res, maxIncA[i] + maxIncB[i]);
        }
        cout << res << "\n";
    }
    return 0;
}
