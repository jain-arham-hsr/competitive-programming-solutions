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

    int n;
    cin >> n;

    vector<string> phones(n);
    for (auto &x : phones)
        cin >> x;

    unordered_map<string, pair<int, int>> subseq;

    for (int p = 0; p < n; p++) {
        set<string> subs;
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j < 10 - i; j++) {
                string sub = phones[p].substr(j, i);
                if (!subs.contains(sub)) {
                    subseq[sub].first++;
                    subseq[sub].second = p;
                    subs.insert(sub);
                }
            }
        }
    }

    for (auto it : subseq) {
        // cout << it.first << " " << it.second << "\n";
        if (it.second.first == 1) {
            if (it.first.size() < phones[it.second.second].size()) {
                phones[it.second.second] = it.first;
            }
        }
    }

    for (auto &x : phones) {
        cout << x << "\n";
    }

    return 0;
}
