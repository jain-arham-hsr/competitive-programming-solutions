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

int calcCost(string &s, string bitMask) {
    int n = s.size();
    int cost = 0;
    int unpairedOpenBrackets = 0;
    for (int i = 0; i < n; i++) {
        if (bitMask[i] == '1')
            continue;
        if (s[i] == '(') {
            unpairedOpenBrackets++;
        } else {
            if (unpairedOpenBrackets > 0) {
                unpairedOpenBrackets--;
                cost += 2;
            }
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        string res(s.size(), '0');
        int minCost = INT_MAX;
        for (int i = 0; i <= k; i++) {
            string bitMask(s.size(), '0');
            int remCnt = i;
            for (int j = 0; j < n; j++) {
                if (s[j] == '(' && remCnt) {
                    bitMask[j] = '1';
                    remCnt--;
                }
            }
            remCnt = k - i;
            for (int j = n - 1; j >= 0; j--) {
                if (s[j] == ')' && remCnt) {
                    bitMask[j] = '1';
                    remCnt--;
                }
            }
            int cost = calcCost(s, bitMask);
            if (cost < minCost) {
                minCost = cost;
                res = bitMask;
            }
        }

        cout << res << "\n";
    }
    return 0;
}
