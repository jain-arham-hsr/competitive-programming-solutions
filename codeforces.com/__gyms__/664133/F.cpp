#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    vector<int> tests(T);
    int maxN = INT_MIN;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        tests[i] = n;
        maxN = max(n, maxN);
    }
    vector<int> fx(maxN + 1);
    for (long long i = 1; i <= maxN; i++) {
        for (long long j = i * i; j <= maxN; j += i) {
            if (i % 2 == 0)
                fx[j]++;
            else
                fx[j]--;
            int secFact = j / i;
            if (secFact != i) {
                if (secFact % 2 == 0)
                    fx[j]++;
                else
                    fx[j]--;
            }
        }
    }
    vector<int> res(maxN + 1);
    res[0] = 0;
    for (int i = 1; i <= maxN; i++) {
        res[i] = (fx[i] == 0) + res[i - 1];
    }

    for (int i = 0; i < T; i++) {
        cout << res[tests[i]] << "\n";
    }

    return 0;
}
