#include <bits/stdc++.h>
using namespace std;

// Function to calculate total chocolates
int chocolateFeast(int n, int c, int m) {
    int chocolates = n / c;   // initial chocolates
    int wrappers = chocolates; // wrappers from initial chocolates

    while (wrappers >= m) {
        int trade = wrappers / m;          // new chocolates from wrappers
        chocolates += trade;               // add to total
        wrappers = wrappers % m + trade;   // update wrappers
    }

    return chocolates;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, c, m;
        cin >> n >> c >> m;
        cout << chocolateFeast(n, c, m) << "\n";
    }
    return 0;
}
