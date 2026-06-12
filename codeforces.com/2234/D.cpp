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
        int n, k;
        cin >> n >> k;

        string strA, strB;
        cin >> strA >> strB;

        int a = 1;
        int b = 2;
        int x = 3;

        long long total_slots = 1LL << k;
        long long cntA = (total_slots + 2) / 3;
        long long cntX = (total_slots + 1) / 3;
        long long cntB = (total_slots) / 3 + 1;

        long long aProd, bProd, xProd;

        long long setBits = 0;
        long long unsetBits = 0;

        for (int i = 0; i < n; i++) {
            if (strA[i] == '1')
                setBits++;
            else
                unsetBits++;
        }

        aProd = setBits * unsetBits;

        setBits = 0;
        unsetBits = 0;

        for (int i = 0; i < n; i++) {
            if (strB[i] == '1')
                setBits++;
            else
                unsetBits++;
        }

        bProd = setBits * unsetBits;

        setBits = 0;
        unsetBits = 0;

        for (int i = 0; i < n; i++) {
            if (strA[i] != strB[i])
                setBits++;
            else
                unsetBits++;
        }

        xProd = setBits * unsetBits;

        long long res = (cntA * aProd) + (cntB * bProd) + (cntX * xProd);

        cout << res << "\n";
    }
    return 0;
}
