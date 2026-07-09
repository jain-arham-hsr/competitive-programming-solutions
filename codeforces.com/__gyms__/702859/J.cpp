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

    int n;
    cin >> n;

    vector<pair<int, string>> prices(n);
    for (auto &x : prices)
        cin >> x.first >> x.second;

    map<string, int> minPrice = {{"A", 4e5},  {"B", 4e5},  {"C", 4e5},
                                 {"AB", 4e5}, {"BC", 4e5}, {"AC", 4e5},
                                 {"ABC", 4e5}};
    for (int i = 0; i < n; i++) {
        string vit = prices[i].second;
        sort(vit.begin(), vit.end());
        if (vit.size() == 2) {
            string f(1, vit[0]), s(1, vit[1]);

            minPrice[f] = min(minPrice[f], prices[i].first);
            minPrice[s] = min(minPrice[s], prices[i].first);
        }
        minPrice[vit] = min(minPrice[vit], prices[i].first);
    }

    minPrice["AB"] = min(minPrice["AB"], minPrice["A"] + minPrice["B"]);
    minPrice["BC"] = min(minPrice["BC"], minPrice["B"] + minPrice["C"]);
    minPrice["AC"] = min(minPrice["AC"], minPrice["A"] + minPrice["C"]);

    vector<ll> combs = {minPrice["A"] + minPrice["B"] + minPrice["C"],
                        minPrice["AB"] + minPrice["C"],
                        minPrice["BC"] + minPrice["A"],
                        minPrice["AC"] + minPrice["B"], minPrice["ABC"]};

    sort(combs.begin(), combs.end());

    if (combs[0] >= 4e5)
        cout << -1;
    else
        cout << combs[0];

    return 0;
}
