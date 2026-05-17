#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        int ind;
        cin >> ind;
        nums[ind] = i;
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (nums[i] < nums[i - 1]) {
            count++;
        }
    }

    cout << count + 1 << "\n";

    return 0;
}
