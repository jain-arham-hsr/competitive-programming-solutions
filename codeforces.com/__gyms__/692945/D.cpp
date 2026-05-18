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

    int n;
    cin >> n;
    int lastC, lastE;
    cin >> lastC >> lastE;
    vector<int> match(n - 1);
    match.reserve(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int c, e;
        cin >> c >> e;
        int m = 0;
        if (e == lastE)
            m += 1;
        if (c == lastC)
            m += 2;
        match[i] = m;
        lastE = e;
        lastC = c;
    }
    int len = n - 1;
    int seg = ceil(sqrt(len));
    vector<int> segComp((len + seg - 1) / seg);
    for (int i = 0; i < (len + seg - 1) / seg; i++) {
        int val = 3;
        for (int j = 0; j < seg; j++) {
            int ind = seg * i + j;
            if (ind < len) {
                watch(ind, i);
                val &= match[ind];
            } else {
                break;
            }
        }
        segComp[i] = val;
    }
    watch(match);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int a = (l + seg - 1) / seg;
        int b = r / seg;
        int rangeAnd = 3;
        bool unsafe = false;
        if (b < a) {
            for (int i = l; i < r; i++) {
                rangeAnd &= match[i];
                if (rangeAnd == 0) {
                    cout << "MARIO IS NOT SAFE\n";
                    unsafe = true;
                    cout << l + 1 << " " << i + 2 << "\n";
                }
            }
            if (unsafe)
                continue;
        } else {
            for (int i = l; i < seg * a; i++) {
                rangeAnd &= match[i];
                if (rangeAnd == 0) {
                    cout << "MARIO IS NOT SAFE\n";
                    unsafe = true;
                    cout << l + 1 << " " << i + 2 << "\n";
                    break;
                }
            }
            if (unsafe)
                continue;
            watch(a, b);
            for (int i = a; i < b; i++) {
                if ((rangeAnd & segComp[i]) == 0) {
                    for (int j = 0; j < seg; j++) {
                        int ind = seg * i + j;
                        if (ind < len) {
                            rangeAnd &= match[ind];
                            if (rangeAnd == 0) {
                                cout << "MARIO IS NOT SAFE\n";
                                unsafe = true;
                                cout << l + 1 << " " << ind + 2 << "\n";
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                } else {
                    rangeAnd &= segComp[i];
                }
                if (unsafe)
                    break;
                watch(rangeAnd);
            }
            if (unsafe)
                continue;
            for (int i = b * seg; i < r; i++) {
                rangeAnd &= match[i];
                if (rangeAnd == 0) {
                    cout << "MARIO IS NOT SAFE\n";
                    unsafe = true;
                    cout << l + 1 << " " << i + 2 << "\n";
                    break;
                }
            }
            if (unsafe)
                continue;
        }
        cout << "MARIO IS SAFE\n";
    }
    return 0;
}
