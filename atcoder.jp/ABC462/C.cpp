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
    T combine(T a, T b) { return a + b; }
    T identity() { return T(0); } // 0 for sum, INT_MAX for min, INT_MIN for max

    // ── public interface
    // ───────────────────────────────────────────────────────
    void update(int idx, T val) { update(1, 0, n - 1, idx, val); }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> pts(n);
    for (auto &x : pts)
        cin >> x.first >> x.second;

    vector<int> yFreq(n + 1);
    SegTree<int> yFreqSeg(n + 1, yFreq);

    sort(pts.begin(), pts.end());

    int res = 0;

    int lastXStartInd = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && pts[i - 1].first != pts[i].first) {
            for (int j = lastXStartInd; j < i; j++) {
                yFreqSeg.update(pts[j].second,
                                yFreqSeg.query(pts[j].second, pts[j].second) +
                                    1);
            }
            lastXStartInd = i;
        }
        if (yFreqSeg.query(0, pts[i].second - 1) == 0)
            res++;
    }

    cout << res;

    return 0;
}
