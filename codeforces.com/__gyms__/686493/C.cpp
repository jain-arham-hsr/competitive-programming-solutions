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

    int x;
    cin >> x;

    int hostel = (x - 2025) % 4;
    int totalFloors = 2 + (x - 2025);

    int goodFloors = 1;

    if (hostel == 0) {
        goodFloors = 1;
    } else if (hostel == 1) {
        goodFloors = 1;
    } else if (hostel == 2) {
        goodFloors = 2;
    } else {
        if (totalFloors > 5) {
            goodFloors = 3;
        } else if (totalFloors > 4) {
            goodFloors = 2;
        } else {
            goodFloors = 1;
        }
    }

    if (totalFloors % goodFloors == 0) {
        cout << 1 << " " << totalFloors / goodFloors;
    } else {
        cout << goodFloors << " " << totalFloors;
    }

    return 0;
}
