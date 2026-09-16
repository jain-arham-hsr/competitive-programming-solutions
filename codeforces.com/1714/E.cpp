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

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        int nonFiveCycleClass = -1;
        int fiveEnding = -1;
        int zeroEnding = -1;

        bool valid = true;

        for (int i = 0; i < n; i++) {
            watch(i);
            if (a[i] % 10 == 5) {
                if (fiveEnding != -1 && fiveEnding != a[i] ||
                    zeroEnding != -1 && zeroEnding != a[i] + 5 ||
                    nonFiveCycleClass != -1) {
                    valid = false;
                    break;
                }
                fiveEnding = a[i];
            } else if (a[i] % 10 == 0) {
                if (zeroEnding != -1 && zeroEnding != a[i] ||
                    fiveEnding != -1 && fiveEnding != a[i] - 5 ||
                    nonFiveCycleClass != -1) {
                    valid = false;
                    break;
                }
                zeroEnding = a[i];
            } else if (a[i] % 10 == 3 || a[i] % 10 == 6 || a[i] % 10 == 7 ||
                       a[i] % 10 == 9) {
                int cycleClass = ((a[i] / 10) + 1) % 2;
                if (zeroEnding != -1 || fiveEnding != -1 ||
                    nonFiveCycleClass != -1 &&
                        nonFiveCycleClass != cycleClass) {
                    valid = false;
                    break;
                }
                nonFiveCycleClass = cycleClass;
            } else {
                int cycleClass = (a[i] / 10) % 2;
                if (zeroEnding != -1 || fiveEnding != -1 ||
                    nonFiveCycleClass != -1 &&
                        nonFiveCycleClass != cycleClass) {
                    valid = false;
                    break;
                }
                nonFiveCycleClass = cycleClass;
            }
        }

        cout << (valid ? "YES\n" : "NO\n");
    }
    return 0;
}
