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

    int x;
    cin >> x;

    string s(99, 'A');

    for (int i = 0; i < 99; i++) {
        if (i % 2 == 1)
            s[i] = 'R';
    }

    int cCnt = 0;
    int rem = x;
    for (int i = 98; i > 0; i -= 2) {
        int aCnt = i / 2;
        if (aCnt <= rem) {
            s[i] = 'C';
            rem -= aCnt;
            if (rem == 0)
                break;
            else {
                cCnt++;
                rem += cCnt;
            }
        }
    }

    cout << s << "\n";

    int res = 0;
    int aCnt = 0;
    for (int i = 0; i < 99; i++) {
        if (s[i] == 'A')
            aCnt++;
        else if (s[i] == 'C')
            res += aCnt;
    }
    watch(res);

    return 0;
}
