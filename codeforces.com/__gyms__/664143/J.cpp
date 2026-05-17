#include <bits/stdc++.h>
using namespace std;

void move(char src, char aux, char dest, int n) {
    if (n == 1) {
        cout << "Move " << src << " to " << dest << "\n";
        return;
    }
    move(src, dest, aux, n - 1);
    cout << "Move " << src << " to " << dest << "\n";
    move(aux, src, dest, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    move('A', 'B', 'C', n);

    return 0;
}
