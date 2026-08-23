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

bool query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    bool isEdge;
    cin >> isEdge;
    return isEdge;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int idx = -1;
        int idx2 = -1;

        for (int i = 1; i <= n; i += 2) {
            int b = i != n ? i + 1 : 1;
            bool exists = i != n ? query(i, i + 1) : query(i, 1);
            watch(i, b);
            if (exists) {
                idx = i;
                idx2 = b;
                break;
            }
        }
        if (idx == -1) {
            cout << "! 1" << endl;
            continue;
        }
        int y = (idx + 1) % n + 1;
        int z = (idx + 2) % n + 1;
        watch(y, z);

        if (query(idx, y)) {
            if (query(idx, z)) {
                cout << "! 2" << endl;
            } else {
                cout << "! 1" << endl;
            }
            continue;
        } else {
            if (query(idx2, y)) {
                if (query(idx2, z)) {
                    cout << "! 2" << endl;
                } else {
                    cout << "! 1" << endl;
                }
            } else {
                cout << "! 1" << endl;
            }
            continue;
        }
    }
    return 0;
}
