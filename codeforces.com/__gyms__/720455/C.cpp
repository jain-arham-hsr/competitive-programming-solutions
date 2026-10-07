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

    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (b % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        int n = a + b + c;

        set<int> s;
        for (int i = 1; i <= 2 * n; i++) {
            s.insert(i);
        }

        vector<pair<int, int>> res;
        res.reserve(n);

        if (b >= 2) {
            int first = *s.begin();
            s.erase(first);
            s.erase(first + 2);

            res.push_back({first, first + 2});

            while (c > 0) {
                first = *s.begin();
                s.erase(first);
                s.erase(first + 3);
                res.push_back({first, first + 3});
                c--;
                watch(s);
            }

            first = *s.begin();
            s.erase(first);
            s.erase(first + 2);

            res.push_back({first, first + 2});

            b -= 2;
            watch(s);
        } else {
            while (c >= 3) {
                int first = *s.begin();
                s.erase(first);
                s.erase(first + 3);
                res.push_back({first, first + 3});
                c--;
                watch(s);
                first = *s.begin();
                s.erase(first);
                s.erase(first + 3);
                res.push_back({first, first + 3});
                c--;
                watch(s);
                first = *s.begin();
                s.erase(first);
                s.erase(first + 3);
                res.push_back({first, first + 3});
                c--;
                watch(s);
            }
            while (c > 0 && a > 0) {
                int first = *s.begin();
                s.erase(first);
                s.erase(first + 3);
                res.push_back({first, first + 3});

                c--;
                watch(s);
                first = *s.begin();
                s.erase(first);
                s.erase(first + 1);
                res.push_back({first, first + 1});
                a--;
                watch(s);
            }
        }

        while (b > 0) {
            int first = *s.begin();
            s.erase(first);
            s.erase(first + 2);
            res.push_back({first, first + 2});
            b--;
            watch(s);
        }

        while (a > 0) {
            int first = *s.begin();
            s.erase(first);
            s.erase(first + 1);
            res.push_back({first, first + 1});
            a--;
            watch(s);
        }

        if (a > 0 || b > 0 || c > 0 || s.size() > 0) {
            cout << "-1" << "\n";
        } else {
            for (auto &x : res) {
                cout << x.first << " " << x.second << "\n";
            }
        }
    }
    return 0;
}
