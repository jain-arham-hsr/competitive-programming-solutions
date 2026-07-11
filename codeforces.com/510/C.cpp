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

    vector<string> names(n);
    for (auto &x : names)
        cin >> x;

    vector<vector<int>> compMat(26, vector<int>(26));

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < names[i - 1].size(); j++) {
            if (j >= names[i].size()) {
                cout << "Impossible";
                return 0;
            }
            char prevWordChar = names[i - 1][j];
            char currWordChar = names[i][j];

            watch(prevWordChar, currWordChar);

            if (prevWordChar == currWordChar)
                continue;
            if (compMat[prevWordChar - 'a'][currWordChar - 'a'] > 0) {
                cout << "Impossible";
                return 0;
            } else {
                compMat[prevWordChar - 'a'][currWordChar - 'a'] = -1;
                compMat[currWordChar - 'a'][prevWordChar - 'a'] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (compMat[i][j] < 0) {
                for (int k = 0; k < 26; k++) {
                    if (compMat[i][k] > 0) {
                        if (compMat[j][k] < 0) {
                            cout << "Impossible";
                            return 0;
                        }
                        compMat[j][k] = 1;
                        compMat[k][j] = -1;
                    }
                }
            }
        }
    }

    vector<pair<int, char>> alphabets(26);

    for (int i = 0; i < 26; i++) {
        int sum = 0;
        for (int j = 0; j < 26; j++) {
            sum += compMat[i][j];
        }
        alphabets[i] = {sum, 'a' + i};
    }

    sort(alphabets.begin(), alphabets.end());

    for (auto x : alphabets)
        cout << x.second;

    return 0;
}
