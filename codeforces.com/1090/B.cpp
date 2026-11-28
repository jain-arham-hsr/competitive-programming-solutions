#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
ostream &operator<<(ostream &os, const T &c);

template <typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &t) {
    os << "(";
    apply(
        [&](auto &...x) {
            bool f = true;
            ((os << (f ? f = false, "" : ", ") << x), ...);
        },
        t);
    return os << ")";
}

template <typename T>
auto operator<<(ostream &os, const T &x) -> decltype(x._fields(), os) {
    return os << x._fields();
}

template <typename T, typename C>
ostream &operator<<(ostream &os, stack<T, C> s) {
    vector<T> v;
    for (; !s.empty(); s.pop())
        v.push_back(s.top());
    reverse(all(v));
    return os << v;
}

template <typename T, typename C>
ostream &operator<<(ostream &os, queue<T, C> q) {
    os << "{";
    for (bool f = true; !q.empty(); q.pop())
        os << (f ? f = false, "" : ", ") << q.front();
    return os << "}";
}

template <typename T, typename C, typename Cmp>
ostream &operator<<(ostream &os, priority_queue<T, C, Cmp> pq) {
    os << "{";
    for (bool f = true; !pq.empty(); pq.pop())
        os << (f ? f = false, "" : ", ") << pq.top();
    return os << "}";
}

template <typename T, typename> ostream &operator<<(ostream &os, const T &c) {
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

#define FIELDS(...)                                                            \
    auto _fields() const { return tie(__VA_ARGS__); }                          \
    template <typename O> bool operator<(const O &o) const {                   \
        return _fields() < o._fields();                                        \
    }                                                                          \
    template <typename O> bool operator>(const O &o) const {                   \
        return _fields() > o._fields();                                        \
    }                                                                          \
    template <typename O> bool operator==(const O &o) const {                  \
        return _fields() == o._fields();                                       \
    }                                                                          \
    template <typename O> bool operator!=(const O &o) const {                  \
        return _fields() != o._fields();                                       \
    }

// ==================================================================== //

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> refr_ord;
    vector<string> bib_ord;
    unordered_map<string, string> refr;

    string curr_line;
    vector<string> res;
    while (getline(cin, curr_line)) {
        for (int i = 0; i < curr_line.size(); i++) {
            if (curr_line[i] == '\\') {
                if (curr_line[i + 1] == 'c') {
                    string ref = "";
                    int j = i + 6;
                    while (j < curr_line.size() && curr_line[j] != '}') {
                        ref += curr_line[j];
                        j++;
                    }
                    refr_ord.push_back(ref);
                } else if (curr_line[i + 1] == 'b' && curr_line[i + 2] == 'i') {
                    string ref = "";
                    int j = i + 9;
                    while (j < curr_line.size() && curr_line[j] != '}') {
                        ref += curr_line[j];
                        j++;
                    }
                    string desc = "";
                    j++;
                    for (; j < curr_line.size(); j++) {
                        desc += curr_line[j];
                    }
                    bib_ord.push_back(ref);
                    refr[ref] = desc;
                }
            }
        }
    }

    int n = refr_ord.size();

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (refr_ord[i] != bib_ord[i]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "Correct";
        return 0;
    }

    cout << "Incorrect\n";
    cout << "\\begin{thebibliography}{99}\n";

    for (auto x : refr_ord) {
        cout << "\\bibitem{" + x + "}" << refr[x] << "\n";
    }
    cout << "\\end{thebibliography}";

    return 0;
}
