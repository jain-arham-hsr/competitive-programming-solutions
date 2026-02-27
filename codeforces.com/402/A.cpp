#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, a, b, v;
    cin >> k >> a >> b >> v;

    int reqSections = (a + v - 1) / v;

    int numSections = (b / (k - 1)) * k;
    int boxes = b / (k - 1);

    if (b % (k - 1) > 0) {
        numSections += (b % (k - 1)) + 1;
        boxes += 1;
    }

    if (reqSections > numSections) {
        cout << boxes + (reqSections - numSections) << "\n";
    } else {
        cout << (reqSections + k - 1) / k;
    }

    return 0;
}
