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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> nextGreater(n);

    stack<int> st1;

    for (int i = n - 1; i >= 0; i--) {
        while (!st1.empty() && a[st1.top()] <= a[i]) {
            st1.pop();
        }
        if (st1.empty())
            nextGreater[i] = n;
        else
            nextGreater[i] = st1.top();

        st1.push(i);
    }

    vector<int> prevGreater(n);

    stack<int> st2;

    for (int i = 0; i < n; i++) {
        while (!st2.empty() && a[st2.top()] <= a[i]) {
            st2.pop();
        }
        if (st2.empty())
            prevGreater[i] = -1;
        else
            prevGreater[i] = st2.top();

        st2.push(i);
    }

    watch(nextGreater);
    watch(prevGreater);

    long long res = a[0];

    for (int i = 0; i < n; i++) {
        res =
            max(res, 1LL * a[i] * min(nextGreater[i] - prevGreater[i] - 1, k));
    }

    cout << res;

    return 0;
}
