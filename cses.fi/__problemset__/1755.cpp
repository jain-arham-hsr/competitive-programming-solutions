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

    string s;
    cin >> s;

    vector<int> freq(26);
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'A']++;
    }

    bool oddExists = false;
    string mid = "";

    string l = "";
    string r = "";

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            if (oddExists) {
                cout << "NO SOLUTION";
                return 0;
            }
            oddExists = true;
            string temp(freq[i], 'A' + i);
            mid = temp;
        } else {
            string temp(freq[i] / 2, 'A' + i);
            l = l + temp;
            r = temp + r;
        }
    }

    cout << l + mid + r;

    return 0;
}
