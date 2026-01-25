#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> movies;
    movies.reserve(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({end, start});
    }

    sort(movies.begin(), movies.end());

    int t = 0;
    int res = 0;

    for (auto &x : movies) {
        if (x.second >= t) {
            t = x.first;
            res++;
        } else
            continue;
    }

    cout << res;

    return 0;
}
