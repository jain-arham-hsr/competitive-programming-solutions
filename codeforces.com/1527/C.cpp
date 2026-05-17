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

        long long sumOfWeights = 0;

        unordered_map<int, long long> counts;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            sumOfWeights += counts[num] * (n - i);
            counts[num] += i + 1;
        }

        cout << sumOfWeights << "\n";
    }
    return 0;
}
