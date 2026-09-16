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

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<int> ans_space = a;
        sort(ans_space.begin(), ans_space.end());
        ans_space.erase(unique(ans_space.begin(), ans_space.end()),
                        ans_space.end());

        int l = -1, r = ans_space.size();
        while (l < r - 1) {
            int mid = l + (r - l) / 2;
            int val = ans_space[mid];
            int cost = 0;
            vector<pair<int, int>> scope;
            vector<int> greater_nums;
            int greater_count = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == val) {
                    scope.push_back({i, i});
                    greater_nums.push_back(greater_count);
                    greater_count = 0;
                } else if (a[i] > val) {
                    greater_count++;
                }
            }
            watch(scope);
            int m = scope.size();
            greater_nums.push_back(greater_count);

            for (int i = 0; i < scope[0].first; i++) {
                if (a[i] < val) {
                    scope[0].first = i;
                    break;
                }
            }
            for (int i = n - 1; i > scope[m - 1].second; i--) {
                if (a[i] < val) {
                    scope[m - 1].second = i;
                    break;
                }
            }
            watch(scope);
            for (int i = 0; i < m - 1; i++) {
                int start = scope[i].second + 1;
                int end = scope[i + 1].first;
                watch(start, end);
                int total_greater = greater_nums[i + 1];
                int greater_left = 0;
                for (int j = start; j < end; j++) {
                    watch(greater_left);
                    if (a[j] > val) {
                        greater_left++;
                    } else {
                        if (greater_left > total_greater - greater_left) {
                            scope[i + 1].first = j;
                            break;
                        } else {
                            scope[i].second = j;
                        }
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                cost += scope[i].second - scope[i].first;
            }
            watch(scope);
            if (cost > k)
                r = mid;
            else
                l = mid;
        }
        cout << ans_space[l] << "\n";
    }
    return 0;
}
