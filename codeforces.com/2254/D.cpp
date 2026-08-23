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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<ll> b(n);
        for (auto &x : b)
            cin >> x;

        map<ll, int> freq;
        map<ll, ll> translate;
        vector<ll> numset;

        for (int i = 0; i < n; i++) {
            freq[b[i]]++;
            if (freq[b[i]] == 1)
                numset.push_back(b[i]);
        }
        sort(numset.begin(), numset.end());

        watch(numset);

        int m = numset.size();

        if (numset[0] != 0) {
            cout << "-1\n";
            continue;
        }

        bool valid = true;
        ll smallestUnused = 1;
        for (int i = 1; i < m; i++) {
            if ((numset[i] - numset[i - 1]) % freq[numset[i - 1]] != 0) {
                valid = false;
                break;
            }
            ll newNum = (numset[i] - numset[i - 1]) / freq[numset[i - 1]];
            translate[numset[i - 1]] = newNum;
            if (newNum + 1 <= smallestUnused) {
                valid = false;
                break;
            }
            smallestUnused = newNum + 1;
        }
        watch(m);
        if (!valid) {
            cout << "-1\n";
            continue;
        }

        translate[numset[m - 1]] = smallestUnused;
        if (!valid) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            cout << translate[b[i]] << " ";
        }
        cout << "\n";
    }
    return 0;
}
