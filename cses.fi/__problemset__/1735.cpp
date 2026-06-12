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

template <typename T> struct LazySegTree {
    int n;
    vector<T> tree, lazy;

    LazySegTree(int n, vector<T> &arr) : n(n), tree(4 * n), lazy(4 * n, T(0)) {
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

    void pushdown(int node, int start, int end, int op) {
        if (lazy[node] == T(0))
            return;
        int mid = (start + end) / 2;
        apply(2 * node, start, mid, lazy[node], op);
        apply(2 * node + 1, mid + 1, end, lazy[node], op);
        lazy[node] = T(0);
    }

    void update(int node, int start, int end, int l, int r, T val, int op) {
        if (r < start || end < l)
            return;
        if (l <= start && end <= r) {
            apply(node, start, end, val, op);
            return;
        }
        pushdown(node, start, end, op);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val, op);
        update(2 * node + 1, mid + 1, end, l, r, val, op);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return identity();
        if (l <= start && end <= r)
            return tree[node];
        pushdown(node, start, end, 1);
        int mid = (start + end) / 2;
        return combine(query(2 * node, start, mid, l, r),
                       query(2 * node + 1, mid + 1, end, l, r));
    }

    // ── change these for sum / min / max
    // ──────────────────────────────────────
    T combine(T a, T b) { return a + b; } // min: min(a,b)  | max: max(a,b)
    T identity() { return T(0); }         // min: INT_MAX   | max: INT_MIN

    void apply(int node, int start, int end, T val, int op) {
        // range add:    tree[node] += val * (end - start + 1); lazy[node] +=
        // val; range assign: tree[node]  = val * (end - start + 1); lazy[node]
        // = val; range min:    tree[node]  = val; lazy[node] = val;  (no size
        // multiply) range max:    tree[node]  = val; lazy[node] = val;  (no
        // size multiply)
        if (op == 1) {
            tree[node] += val * (end - start + 1);
            lazy[node] += val;
        } else {
            tree[node] = val * (end - start + 1);
            lazy[node] = val;
        }
    }

    // ── public interface
    // ───────────────────────────────────────────────────────
    void update(int l, int r, T val, int op) {
        update(1, 0, n - 1, l, r, val, op);
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;

    LazySegTree<int> numsSeg(n, nums);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1 || type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            numsSeg.update(a, b, x, type);
        } else {
            int a, b;
            cin >> a >> b;
            cout << numsSeg.query(a, b) << "\n";
        }
    }

    return 0;
}
