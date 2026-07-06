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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T>
struct OrderedSet
    : __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>,
                       __gnu_pbds::rb_tree_tag,
                       __gnu_pbds::tree_order_statistics_node_update> {};

template <typename T> struct OrderedMultiSet {
  private:
    int id = 0;
    __gnu_pbds::tree<pair<T, int>, __gnu_pbds::null_type, less<pair<T, int>>,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>
        s;

  public:
    void insert(T x) { s.insert({x, id++}); }
    void erase(T x) { s.erase(s.lower_bound({x, 0})); }
    int size() { return s.size(); }
    int order_of_key(T x) { return s.order_of_key({x, 0}); } // # elements < x
    T find_by_order(int k) {
        return s.find_by_order(k)->first;
    } // kth smallest (0-indexed)
    bool contains(T x) {
        return s.lower_bound({x, 0}) != s.upper_bound({x, INT_MAX});
    }
    int count(T x) {
        return order_of_key(x + 1) - order_of_key(x);
    } // only works for integral T
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (auto &x : nums)
        cin >> x;

    vector<long long> prefSum(n + 1);
    partial_sum(nums.begin(), nums.end(), prefSum.begin() + 1);

    OrderedSet<int> des;
    des.insert(0);
    des.insert(n + 1);

    OrderedMultiSet<long long> segSums;
    segSums.insert(prefSum[n] - prefSum[0]);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        int pos = des.order_of_key(p) - 1;
        int lowerInd = *des.find_by_order(pos);
        int upperInd = *des.find_by_order(pos + 1);

        watch(lowerInd, upperInd);

        long long oldSum = prefSum[upperInd - 1] - prefSum[lowerInd];
        long long lSum = prefSum[p - 1] - prefSum[lowerInd];
        long long rSum = prefSum[upperInd - 1] - prefSum[p];

        watch(oldSum, lSum, rSum);

        des.insert(p);

        segSums.erase(oldSum);
        segSums.insert(lSum);
        segSums.insert(rSum);

        cout << segSums.find_by_order(i + 1) << "\n";
    }

    return 0;
}
