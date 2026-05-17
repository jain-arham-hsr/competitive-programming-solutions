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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int oneCnts = count(s.begin(), s.end(), '1');
        if (oneCnts == 0) {
            cout << 0 << "\n";
            continue;
        }

        int medianOneInd = (oneCnts + 1) / 2;

        int medianOnePos = -1;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                temp++;
            if (temp == medianOneInd) {
                medianOnePos = i;
                break;
            }
        }

        int curr = medianOnePos - medianOneInd + 1;

        int cost = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cost += abs(curr - i);
                curr++;
            }
        }

        cout << cost << "\n";
    }
    return 0;
}
