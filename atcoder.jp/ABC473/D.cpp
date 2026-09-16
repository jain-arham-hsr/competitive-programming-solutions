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

    int n, k;
    cin >> n >> k;
    watch(n);

    vector<int> hasBreakOnFirst(11);

    for (ll i1 = 0; i1 <= k; i1++) {
        if (i1 > k || hasBreakOnFirst[10]) {
            break;
        }
        for (ll i2 = 0; i2 <= k / 2; i2++) {
            if ((n < 2 && i2 > 0) || i1 + 2 * i2 > k || hasBreakOnFirst[10]) {
                break;
                if (i2 == 1)
                    hasBreakOnFirst[2] = true;
            }
            for (ll i3 = 0; i3 <= k / 3; i3++) {
                if ((n < 3 && i3 > 0) || i1 + 2 * i2 + 3 * i3 > k ||
                    hasBreakOnFirst[10]) {
                    break;
                    if (i3 == 1)
                        hasBreakOnFirst[3] = true;
                }
                for (ll i4 = 0; i4 <= k / 4; i4++) {
                    if ((n < 4 && i4 > 0) ||
                        i1 + 2 * i2 + 3 * i3 + 4 * i4 > k ||
                        hasBreakOnFirst[10]) {
                        break;
                        if (i4 == 1)
                            hasBreakOnFirst[4] = true;
                    }
                    for (ll i5 = 0; i5 <= k / 5; i5++) {
                        if ((n < 5 && i5 > 0) ||
                            i1 + 2 * i2 + 3 * i3 + 4 * i4 + 5 * i5 > k ||
                            hasBreakOnFirst[10]) {
                            break;
                            if (i5 == 1)
                                hasBreakOnFirst[5] = true;
                        }
                        for (ll i6 = 0; i6 <= k / 6; i6++) {
                            if ((n < 6 && i6 > 0) ||
                                i1 + 2 * i2 + 3 * i3 + 4 * i4 + 5 * i5 +
                                        6 * i6 >
                                    k ||
                                hasBreakOnFirst[10]) {
                                break;
                                if (i6 == 1)
                                    hasBreakOnFirst[6] = true;
                            }
                            for (ll i7 = 0; i7 <= k / 7; i7++) {
                                if ((n < 7 && i7 > 0) ||
                                    i1 + 2 * i2 + 3 * i3 + 4 * i4 + 5 * i5 +
                                            6 * i6 + 7 * i7 >
                                        k ||
                                    hasBreakOnFirst[10]) {
                                    break;
                                    if (i7 == 1)
                                        hasBreakOnFirst[7] = true;
                                }
                                for (ll i8 = 0; i8 <= k / 8; i8++) {
                                    if ((n < 8 && i8 > 0) ||
                                        i1 + 2 * i2 + 3 * i3 + 4 * i4 + 5 * i5 +
                                                6 * i6 + 7 * i7 + 8 * i8 >
                                            k ||
                                        hasBreakOnFirst[10]) {
                                        break;
                                        if (i8 == 1)
                                            hasBreakOnFirst[8] = true;
                                    }
                                    for (ll i9 = 0; i9 <= k / 9; i9++) {
                                        if ((n < 9 && i9 > 0) ||
                                            i1 + 2 * i2 + 3 * i3 + 4 * i4 +
                                                    5 * i5 + 6 * i6 + 7 * i7 +
                                                    8 * i8 + 9 * i9 >
                                                k ||
                                            hasBreakOnFirst[10]) {
                                            break;
                                            if (i9 == 1)
                                                hasBreakOnFirst[9] = true;
                                        }
                                        for (ll i10 = 0; i10 <= k / 10; i10++) {
                                            if ((n < 10 && i10 > 0) ||
                                                i1 + 2 * i2 + 3 * i3 + 4 * i4 +
                                                        5 * i5 + 6 * i6 +
                                                        7 * i7 + 8 * i8 +
                                                        9 * i9 + 10 * i10 >
                                                    k) {
                                                if (i10 == 1)
                                                    hasBreakOnFirst[10] = true;
                                                break;
                                            }
                                            if (i1 + 2 * i2 + 3 * i3 + 4 * i4 +
                                                    5 * i5 + 6 * i6 + 7 * i7 +
                                                    8 * i8 + 9 * i9 +
                                                    10 * i10 ==
                                                k) {
                                                if (n >= 1) {
                                                    cout << i1 << " ";
                                                }
                                                if (n >= 2) {
                                                    cout << i2 << " ";
                                                }
                                                if (n >= 3) {
                                                    cout << i3 << " ";
                                                }
                                                if (n >= 4) {
                                                    cout << i4 << " ";
                                                }
                                                if (n >= 5) {
                                                    cout << i5 << " ";
                                                }
                                                if (n >= 6) {
                                                    cout << i6 << " ";
                                                }
                                                if (n >= 7) {
                                                    cout << i7 << " ";
                                                }
                                                if (n >= 8) {
                                                    cout << i8 << " ";
                                                }
                                                if (n >= 9) {
                                                    cout << i9 << " ";
                                                }
                                                if (n >= 10) {
                                                    cout << i10 << " ";
                                                }
                                                cout << "\n";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
