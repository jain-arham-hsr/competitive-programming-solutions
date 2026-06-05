#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int factorPairs = 1;
        int sqrtN = sqrt(n);
        for (int i = 2; i <= sqrtN; i++) {
            while (n % i == 0) {
                if (n / i != i)
                    factorPairs++;
                n /= i;
                if (factorPairs == 3)
                    break;
            }
            if (factorPairs == 3)
                break;
        }
        cout << factorPairs << "\n";
    }
}
