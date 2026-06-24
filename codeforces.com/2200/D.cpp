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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;

        vector<int> inner(nums.begin() + x, nums.begin() + y);

        vector<int> outer(nums.begin(), nums.begin() + x);

        outer.insert(outer.end(), nums.begin() + y, nums.end());

        int minEle = inner[0];
        int minInd = 0;
        for (int i = 0; i < inner.size(); i++) {
            if (inner[i] < minEle) {
                minEle = inner[i];
                minInd = i;
            }
        }

        int b = 0;
        for (; b < outer.size(); b++) {
            if (outer[b] > minEle) {
                break;
            }
            cout << outer[b] << " ";
        }

        for (int i = 0; i < inner.size(); i++) {
            cout << inner[(i + minInd) % inner.size()] << " ";
        }

        for (int i = b; i < outer.size(); i++) {
            cout << outer[i] << " ";
        }

        cout << "\n";
    }
    return 0;
}
