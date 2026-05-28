#include <bits/stdc++.h>
using namespace std;

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

long long merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1);
    long long inv = 0;
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            inv += left.size() - i;
            arr[k++] = right[j++];
        }
    }
    while (i < left.size())
        arr[k++] = left[i++];
    while (j < right.size())
        arr[k++] = right[j++];
    return inv;
}

long long mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    return mergeSort(arr, l, mid) + mergeSort(arr, mid + 1, r) +
           merge(arr, l, mid, r);
}

long long countInversions(vector<int> arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> trip(n);
        for (int i = 0; i < n; i++) {
            cin >> trip[i].first >> trip[i].second;
        }
        sort(trip.begin(), trip.end());
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = trip[i].second;
        }
        cout << countInversions(nums) << "\n";
    }
    return 0;
}
