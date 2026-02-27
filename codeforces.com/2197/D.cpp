#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<long long> freq(1e9 + 1);
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            freq[num]++;
            nums[i] = num;
        }
        vector<long long> prefSum(n);
        partial_sort(freq.begin(), freq.end(), prefSum.begin());
        vector<int>
        for (int i = 0; i < n; i++) {

        }
    }
    return 0;
}
