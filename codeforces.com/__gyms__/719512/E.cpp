#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;

ostream &operator<<(ostream &os, i128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9)
        os << (i128)(x / 10);
    return os << (int)(x % 10);
}

ostream &operator<<(ostream &os, u128 x) {
    if (x > 9)
        os << (u128)(x / 10);
    return os << (int)(x % 10);
}

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

    vector<int> c(n);
    for (auto &x : c)
        cin >> x;

    vector<int> res;

    vector<int> vst(k + 1);
    vector<int> existsInStack(k + 1);

    bool ok = true;

    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vst[c[i]]) {
            st.push(c[i]);
            existsInStack[c[i]] = true;
            vst[c[i]] = true;
        } else {
            if (!existsInStack[c[i]])
                ok = false;
            while (st.size() && st.top() != c[i]) {
                res.push_back(st.top());
                existsInStack[st.top()] = false;
                st.pop();
            }
        }
    }

    while (st.size()) {
        res.push_back(st.top());
        st.pop();
    }

    watch(res);

    if (res.size() != k || !ok)
        cout << -1;
    else {
        for (auto &x : res)
            cout << x << " ";
    }

    return 0;
}
