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
        string s;
        cin >> s;

        string match = "abacaba";

        bool ok = true;
        int start = -1;

        for (int i = 0; i < n; i++) {
            bool same = true;
            for (int j = 0; j < 7; j++) {
                // if (i + j < n)
                // watch(s[i + j], match[j]);
                if (i + j >= n || s[i + j] != match[j])
                    same = false;
            }
            // watch(same);
            if (same && start >= 0) {
                ok = false;
                break;
            }
            if (same)
                start = i;
            // watch(start);
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        if (start >= 0) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '?')
                    s[i] = 'x';
            }

            cout << "YES\n";
            cout << s << "\n";
            continue;
        }

        for (int i = 0; i < n; i++) {

            string sCopy = s;

            bool same = true;
            for (int j = 0; j < 7; j++) {
                if (i + j < n && s[i + j] == '?') {
                    sCopy[i + j] = match[j];
                }
                // if (i + j < n)
                //     watch(sCopy[i + j], match[j]);
                if (i + j >= n || sCopy[i + j] != match[j])
                    same = false;
            }

            watch(sCopy);
            if (same) {
                bool same2 = true;
                for (int j = 0; j < 7; j++) {
                    if (i + 4 + j >= n || sCopy[i + 4 + j] != match[j])
                        same2 = false;
                }
                bool same3 = true;
                for (int j = 0; j < 7; j++) {
                    if (i + 6 + j >= n || sCopy[i + 6 + j] != match[j])
                        same3 = false;
                }
                bool same4 = true;
                if (i - 6 >= 0) {
                    for (int j = 0; j < 7; j++) {
                        if (i - 6 + j >= n || sCopy[i + j - 6] != match[j])
                            same4 = false;
                    }
                } else {
                    same4 = false;
                }
                bool same5 = true;
                if (i - 4 >= 0) {
                    for (int j = 0; j < 7; j++) {
                        if (i - 4 + j >= n || sCopy[i + j - 4] != match[j])
                            same5 = false;
                    }
                } else {
                    same5 = false;
                }
                watch(same2, same3);
                if (!same2 && !same3 && !same4 && !same5) {
                    start = i;
                    break;
                }
            }
        }

        if (start < 0) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < 7; i++) {
            s[start + i] = match[i];
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '?')
                s[i] = 'x';
        }

        cout << "YES\n";
        cout << s << "\n";
    }
    return 0;
}
