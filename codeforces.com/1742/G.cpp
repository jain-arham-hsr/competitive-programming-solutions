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
        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;
        sort(nums.rbegin(), nums.rend());
        int orSum = 0;
        vector<int> primary;
        primary.reserve(n);
        vector<int> aux;
        aux.reserve(n);
        for (int i = 0; i < n; i++) {
            int msb = 31;
            for (; msb >= 0; msb--) {
                if ((nums[i] & (1 << msb)) > 0)
            }
            if ((orSum | nums[i]) != orSum)
                primary.push_back(nums[i]);
            else
                aux.push_back(nums[i]);
            orSum |= nums[i];
        }
        for (auto &x : primary)
            cout << x << " ";
        for (auto &x : aux)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
