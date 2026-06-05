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

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
        cin >> x;
    int firstNum = nums[0], lastFirstInd = 0;
    int secondNum = nums[0], lastSecondInd = 0;
    int maxLen = 1;
    int st = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] == secondNum) {
            lastSecondInd = i;
        } else if (nums[i] == firstNum) {
            lastFirstInd = i;
        } else {
            if (firstNum == secondNum) {
                firstNum = nums[i];
                lastFirstInd = i;
            } else if (lastFirstInd < lastSecondInd) {
                firstNum = nums[i];
                st = lastFirstInd + 1;
                lastFirstInd = i;
            } else {
                secondNum = nums[i];
                st = lastSecondInd + 1;
                lastSecondInd = i;
            }
        }
        watch(st);
        watch(firstNum, lastFirstInd, secondNum, lastSecondInd);
        maxLen = max(maxLen, max(lastFirstInd, lastSecondInd) - st + 1);
        watch(maxLen);
    }
    cout << maxLen << "\n";

    return 0;
}
