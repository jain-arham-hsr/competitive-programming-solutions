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
        int n;
        cin >> n;

        vector<vector<int>> blogs;
        blogs.reserve(n);
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;

            vector<int> rawInp(m);

            for (auto &x : rawInp)
                cin >> x;

            vector<int> b;
            b.reserve(m);

            vector<bool> exists(int(1e6) + 1);
            for (int j = m - 1; j >= 0; j--) {
                if (exists[rawInp[j]])
                    continue;
                b.push_back(rawInp[j]);
                exists[rawInp[j]] = true;
            }

            blogs.push_back(b);
        }

        vector<bool> used(int(1e6) + 1);
        while (blogs.size() > 0) {
            sort(blogs.begin(), blogs.end());
            for (auto x : blogs[0]) {
                cout << x << " ";
                used[x] = true;
            }

            for (int i = 1; i < blogs.size(); i++) {
                vector<int> newB;
                newB.reserve(blogs[i].size());
                for (int j = 0; j < blogs[i].size(); j++) {
                    if (used[blogs[i][j]])
                        continue;
                    newB.push_back(blogs[i][j]);
                }
                blogs[i] = newB;
            }

            blogs.assign(blogs.begin() + 1, blogs.end());
        }
        cout << "\n";
    }
    return 0;
}
