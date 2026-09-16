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
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<int> freq(n + 5);
        for (int i = 0; i < n; i++) {
            if (a[i] <= n)
                freq[a[i]]++;
        }

        vector<int> freqA(n + 5);
        vector<int> freqB(n + 5);
        vector<int> freqC(n + 5);

        bool valid = true;
        int mex3 = 0;
        int mex2 = 0;
        int mex1 = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] >= 3 && mex3 == i) {
                mex3++;
                mex2++;
                mex1++;
                freqA[i] += freq[i] - 2;
                freqB[i]++;
                freqC[i]++;
            } else if (freq[i] >= 2 && mex2 == i) {
                mex2++;
                mex1++;
                freqA[i] += freq[i] - 1;
                freqB[i]++;
            } else if (freq[i] >= 1 && mex1 == i) {
                if (mex2 + mex3 >= i + 1) {
                    mex1++;
                    freqA[i] += freq[i];
                } else if (mex3 < mex1) {
                    freqC[i]++;
                } else {
                    valid = false;
                    break;
                }
            } else if (freq[i] == 0) {
                break;
            }
        }

        if (!valid) {
            cout << "NO\n";
            continue;
        }

        watch(mex1, mex2, mex3);

        string res(n, 'C');

        for (int i = 0; i < n; i++) {
            if (a[i] >= mex1)
                res[i] = 'C';
            else if (freqA[a[i]] > 0) {
                res[i] = 'A';
                freqA[a[i]]--;
            } else if (freqB[a[i]] > 0) {
                res[i] = 'B';
                freqB[a[i]]--;
            } else {
                res[i] = 'C';
                freqC[a[i]]--;
            }
        }

        watch(freqA, freqB, freqC);

        cout << "YES\n" << res << "\n";
    }
    return 0;
}
