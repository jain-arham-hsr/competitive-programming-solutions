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
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> nums(n);
        for (auto &x : nums)
            cin >> x;

        vector<int> left(n + 1);
        vector<int> right(n + 1);

        for (int i = 0; i < l; i++) {
            left[nums[i]]++;
        }
        for (int i = l; i < n; i++) {
            if (left[nums[i]] > 0)
                left[nums[i]]--;
            else
                right[nums[i]]++;
        }

        int sumLeft = accumulate(left.begin(), left.end(), 0);
        int sumRight = accumulate(right.begin(), right.end(), 0);

        if (sumLeft == sumRight) {
            cout << sumLeft << "\n";
            continue;
        }

        ll res = 0;

        if (sumRight > sumLeft) {
            swap(left, right);
            swap(sumLeft, sumRight);
        }

        watch(left, right);

        for (int i = 0; i <= n; i++) {
            while (sumLeft > sumRight && left[i] > 1) {
                sumLeft -= 2;
                left[i] -= 2;
                res++;
            }
        }
        watch(res, sumLeft, sumRight, left, right);

        res += sumRight;
        res += sumLeft - sumRight;

        cout << res << "\n";
    }
    return 0;
}
