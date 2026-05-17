#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    vector<int> diffs(n);

    for (int i = 0; i < n; i++) {
        diffs[i] = a[i] - b[i];
    }

    sort(diffs.begin(), diffs.end());

    long long score = 0;

    int l = 0, r = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (diffs[l] + diffs[r] > 0) {
                score += diffs[r];
                r--;
            } else {
                l++;
            }
        } else {
            if (diffs[l] + diffs[r] < 0) {
                score += diffs[l];
                l++;
            } else {
                r--;
            }
        }
    }
    if (score > 0)
        cout << "Alice";
    else if (score < 0)
        cout << "Bob";
    else
        cout << "Tie";

    return 0;
}
