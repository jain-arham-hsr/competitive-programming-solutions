#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

template <typename T> class OrderedSet {
  private:
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
        st;

  public:
    int countElementsLessThanX(T x) { return st.order_of_key(x); }
    int countElementsAtleastX(T x) {
        return st.size() - countElementsLessThanX(x);
    }
    int getKthElement(int k) { return *st.find_by_order(k); }
    void insert(T x) { st.insert(x); }
    void erase(T x) { st.erase(x); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (auto &x : p)
        cin >> x;

    OrderedSet<pair<int, int>> os;

    for (int i = 0; i < n; i++) {
        os.insert({p[i], i});
    }

    while (q--) {
        char type;
        int num1, num2;
        cin >> type >> num1 >> num2;
        watch(type, num1, num2);
        if (type == '!') {
            num1--;
            os.erase({p[num1], num1});
            p[num1] = num2;
            os.insert({p[num1], num1});
        } else {
            cout << os.countElementsLessThanX({num2 + 1, -1}) -
                        os.countElementsLessThanX({num1, -1})
                 << "\n";
        }
    }
    return 0;
}
