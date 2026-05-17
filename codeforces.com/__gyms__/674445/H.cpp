#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string init, fin;
    cin >> init >> fin;

    int count = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (init[i] != fin[i]) {
            if (!flag) {
                count++;
                flag = true;
            }
        } else {
            flag = false;
        }
    }

    cout << count << "\n";

    return 0;
}
