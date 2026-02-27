#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int parentNode;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                parentNode = adj[i][0];
            }
        }
        int y = adj[parentNode].size() - 1;
        int x = m / (y + 1);
        cout << x << " " << y << "\n";
    }
    return 0;
}
