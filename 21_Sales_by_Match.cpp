#include <bits/stdc++.h>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> sockCount;
    int pairs = 0;

    // Count frequency of each sock color
    for (int color : ar) {
        sockCount[color]++;
    }

    // Calculate total pairs
    for (auto &entry : sockCount) {
        pairs += entry.second / 2;
    }

    return pairs;
}

int main() {
    int n;
    cin >> n;  // number of socks
    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];  // sock colors
    }

    int result = sockMerchant(n, ar);
    cout << result << endl;

    return 0;
}
