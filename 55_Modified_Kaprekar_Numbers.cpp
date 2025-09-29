#include <bits/stdc++.h>
using namespace std;

void kaprekarNumbers(int p, int q) {
    bool found = false;

    for (int i = p; i <= q; i++) {
        long long sq = 1LL * i * i;  // avoid overflow

        int d = to_string(i).size(); // number of digits in i

        long long power = pow(10, d);
        long long R = sq % power;
        long long L = sq / power;

        if (L + R == i) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) cout << "INVALID RANGE";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, q;
    cin >> p >> q;

    kaprekarNumbers(p, q);

    return 0;
}
