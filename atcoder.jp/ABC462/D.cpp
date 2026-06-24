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

    int n, d;
    cin >> n >> d;
    vector<int> s, e;
    for (int i = 0; i < n; i++) {
        int si, ei;
        cin >> si >> ei;
        if (ei - si >= d) {
            s.push_back(si);
            e.push_back(ei);
        }
    }

    sort(s.begin(), s.end());
    sort(e.begin(), e.end());

    int m = s.size();
    int startInd = 0;
    long long sum = 0;
    long long res = 0;

    for (int i = 0; i < m; i++) {
        while (startInd < i && e[startInd] < s[i] + d) {
            sum -= e[startInd];
            startInd++;
        }
        long long k = i - startInd;
        res += sum - k * (s[i] + d - 1);
        sum += e[i];
    }

    cout << res << endl;
}
