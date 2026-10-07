#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;

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

pair<ll, ll> getWealthiestFaction(OrderedSet<pair<ll, ll>> &os) {
    ll n = os.size();
    ll w = (*os.find_by_order(n - 1)).first;
    return *os.find_by_order(os.order_of_key({w, -1}));
}

void distribute(ll &sum, OrderedSet<pair<ll, ll>> &os, OrderedSet<ll> &osInd,
                vector<ll> &nums, ll ind) {
    int ord = osInd.order_of_key(ind);
    watch(ind, ord);
    sum -= nums[ind];
    if (ord + 1 < osInd.size()) {
        int nextInd = *osInd.find_by_order(ord + 1);
        watch(nextInd);
        os.erase({nums[nextInd], nextInd});
        sum += nums[ind] / 2;
        nums[nextInd] += nums[ind] / 2;
        os.insert({nums[nextInd], nextInd});
    }
    if (ord - 1 >= 0) {
        int prevInd = *osInd.find_by_order(ord - 1);
        watch(prevInd);
        os.erase({nums[prevInd], prevInd});
        sum += nums[ind] / 2;
        nums[prevInd] += nums[ind] / 2;
        os.insert({nums[prevInd], prevInd});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (auto &x : nums)
        cin >> x;

    OrderedSet<pair<ll, ll>> os;
    OrderedSet<ll> osInd;

    ll sum = 0;

    for (ll i = 0; i < n; i++) {
        os.insert({nums[i], i});
        osInd.insert(i);
        sum += nums[i];
    }

    for (ll i = 0; i < n; i++) {
        pair<ll, ll> largest = getWealthiestFaction(os);
        ll lw = largest.first;
        ll li = largest.second;
        watch(sum, lw, li);
        if (lw > sum - lw) {
            pair<ll, ll> smallest = *os.find_by_order(0);
            ll sw = smallest.first;
            ll si = smallest.second;
            distribute(sum, os, osInd, nums, si);
            cout << si + 1 << " " << sw << "\n";
            os.erase(smallest);
            osInd.erase(si);
        } else {
            distribute(sum, os, osInd, nums, li);
            cout << li + 1 << " " << lw << "\n";
            os.erase(largest);
            osInd.erase(li);
        }
        watch(os, nums);
    }

    // os.insert({2, 2});
    // os.insert({1, 3});
    // os.insert({2, 1});
    // watch(os);

    // watch(*os.find_by_order(os.order_of_key({2, 0})));
    // watch(os);

    return 0;
}
