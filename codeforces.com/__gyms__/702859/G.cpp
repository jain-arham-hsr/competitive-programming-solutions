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

        vector<pair<int, int>> l(n);
        vector<pair<int, int>> r(n);

        for (int i = 0; i < n; i++) {
            l[i] = {0, i + 1};
            r[i] = {0, i + 1};
        }

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            l[num - 1].first++;
        }
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            r[num - 1].first++;
        }

        sort(l.rbegin(), l.rend());
        sort(r.rbegin(), r.rend());

        vector<int> set1;
        set1.reserve(2 * k);
        vector<int> set2;
        set2.reserve(2 * k);

        int curr = 0;
        while (set1.size() < 2 * k) {
            for (int i = 0; i < l[curr].first; i++) {
                set1.push_back(l[curr].second);
            }
            curr++;
        }
        curr = 0;
        while (set2.size() < 2 * k) {
            for (int i = 0; i < r[curr].first; i++) {
                set2.push_back(r[curr].second);
            }
            curr++;
        }

        for (auto &x : set1)
            cout << x << " ";
        cout << "\n";
        for (auto &x : set2)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
