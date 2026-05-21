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

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int res = 0;
        int beforeTwo = 0;
        int afterOneThree = 0;
        bool twoOccurred = false;
        bool oneThreeOccurred = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '4')
                res++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '2')
                twoOccurred = true;
            else if ((s[i] == '1' || s[i] == '3') && twoOccurred)
                beforeTwo++;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' || s[i] == '3')
                oneThreeOccurred = true;
            else if (s[i] == '2' && oneThreeOccurred)
                afterOneThree++;
        }
        res += min(beforeTwo, afterOneThree);
        cout << res << "\n";
    }
    return 0;
}
