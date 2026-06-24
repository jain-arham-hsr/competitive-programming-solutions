#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

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

template <typename T> struct SegTree {
    int n;
    vector<T> tree;

    SegTree(int n, vector<T> &arr) : n(n), tree(4 * n) {
        build(1, 0, n - 1, arr);
    }

    void build(int node, int start, int end, vector<T> &arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return identity();
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return combine(query(2 * node, start, mid, l, r),
                       query(2 * node + 1, mid + 1, end, l, r));
    }

    // ── change these for sum / min / max
    // ──────────────────────────────────────
    T combine(T a, T b) {
        if (a.first < b.first)
            return a;
        else
            return b;
    }
    T identity() {
        return T({LLONG_MAX, -1});
    } // 0 for sum, INT_MAX for min, INT_MIN for max

    // ── public interface
    // ───────────────────────────────────────────────────────
    void update(int idx, T val) { update(1, 0, n - 1, idx, val); }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> basePrice(n);
    for (auto &x : basePrice)
        cin >> x;

    vector<pair<int, int>> leftOrdPrice(n);
    vector<pair<int, int>> rightOrdPrice(n);

    for (int i = 0; i < n; i++) {
        rightOrdPrice[i] = {basePrice[i] + i, i};
        leftOrdPrice[i] = {basePrice[i] - i, i};
    }

    SegTree<pair<int, int>> leftOrdSegTree(n, leftOrdPrice);
    SegTree<pair<int, int>> rightOrdSegTree(n, rightOrdPrice);

    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            basePrice[k] = x;
            rightOrdPrice[k] = {basePrice[k] + k, k};
            leftOrdPrice[k] = {basePrice[k] - k, k};
            leftOrdSegTree.update(k, leftOrdPrice[k]);
            rightOrdSegTree.update(k, rightOrdPrice[k]);
        } else {
            int k;
            cin >> k;
            k--;
            int leftRes = leftOrdSegTree.query(0, k).second;
            int rightRes = rightOrdSegTree.query(k, n - 1).second;
            int res = min(basePrice[leftRes] + k - leftRes,
                          basePrice[rightRes] + rightRes - k);
            cout << res << "\n";
        }
    }
    return 0;
}
