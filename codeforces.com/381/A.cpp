#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cards(n);
    for (auto &x : cards)
        cin >> x;

    int s_sum = 0;
    int d_sum = 0;

    int l = 0, r = n - 1;

    bool isCurrSereja = 1;

    while (l <= r) {
        int maxNum;
        if (cards[l] < cards[r]) {
            maxNum = cards[r];
            r--;
        } else {
            maxNum = cards[l];
            l++;
        }
        if (isCurrSereja)
            s_sum += maxNum;
        else
            d_sum += maxNum;

        isCurrSereja = !isCurrSereja;
    }
    cout << s_sum << " " << d_sum;

    return 0;
}
