#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

static const int MOD = 1000000007;
const int MAX_PRIME_LIMIT = 6000000;
vector<int> prime;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class DSU {
    vector<int> parent, size;

  public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    bool same(int i, int j) { return find(i) == find(j); }

    int getsize(int i) { return size[find(i)]; }
};

class SegmentTree {
  private:
    int n;
    vector<long long> tree;

    void build(int node, int start, int end, const vector<int> &arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = start + (end - start) / 2;
        long long p1 = query(2 * node, start, mid, l, r);
        long long p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

  public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * max(1, n), 0);
        if (n > 0)
            build(1, 0, n - 1, arr);
    }

    void update(int idx, int val) {
        if (n > 0 && idx >= 0 && idx < n)
            update(1, 0, n - 1, idx, val);
    }

    long long query(int l, int r) {
        if (n == 0 || l > r || l < 0 || r >= n)
            return 0;
        return query(1, 0, n - 1, l, r);
    }
};

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    } else {
        return a[1] > b[1];
    }
}

long long modPow(long long a, long long b) {
    a %= MOD;
    if (a < 0)
        a += MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (__int128)res * a % MOD;
        a = (__int128)a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long modInv(long long a) { return modPow(a, MOD - 2); }

void precomputePrimes() {
    vector<bool> is_prime(MAX_PRIME_LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; 1LL * i * i <= MAX_PRIME_LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_PRIME_LIMIT; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= MAX_PRIME_LIMIT; i++) {
        if (is_prime[i])
            prime.push_back(i);
    }
}

struct Compare {
    bool operator()(const pair<int, long long> &a,
                    const pair<int, long long> &b) const {
        return a.second > b.second;
    }
};

void solve() {
    int k;
    int a;
    cin >> k >> a;

    vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    long long time = 0;
    int curr = a;

    for (int i = 0; i < k; i++) {
        time += abs(curr - arr[i]);

        if ((time + arr[i]) % 2 == 0) {
            time++;
        } else {
            time += 2;
        }

        curr = arr[i];
    }

    cout << time << '\n';
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
