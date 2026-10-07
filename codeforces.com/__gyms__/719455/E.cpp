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

void func(queue<int> &q0, queue<int> &q1, queue<int> &q2, vector<int> &rem,
          int &maxVal) {
    if (!q0.size()) {
        maxVal++;
        watch(maxVal);
        rem[maxVal] = 2;
        q1.push(maxVal);
        q2.push(maxVal);
    } else {
        int currInd = q0.front();
        watch(currInd);
        q0.pop();
        rem[currInd]--;
        if (rem[currInd] == 0) {
            rem[currInd] = 3;
            q0.push(currInd);
            q1.push(currInd);
            q2.push(currInd);
        }
    }
    watch(rem);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> rem(n + 1);

    rem[1] = 3;

    queue<int> O;
    queue<int> E;
    queue<int> G;
    O.push(1);
    E.push(1);
    G.push(1);

    int maxVal = 1;

    for (int i = 0; i < n; i++) {
        watch(i, s[i]);
        if (s[i] == 'O') {
            func(O, E, G, rem, maxVal);
        } else if (s[i] == 'E') {
            func(E, O, G, rem, maxVal);
        } else {
            func(G, E, O, rem, maxVal);
        }

        // watch(maxVal);
    }

    cout << maxVal << "\n";

    return 0;
}
