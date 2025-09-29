#include <bits/stdc++.h>
using namespace std;

string biggerIsGreater(string w) {
    int n = w.size();
    int i = n - 2;

    // Step 1: Find first decreasing element from the right
    while (i >= 0 && w[i] >= w[i + 1]) i--;
    if (i < 0) return "no answer"; // Entire string is non-increasing

    // Step 2: Find the smallest character on right of i that is larger than w[i]
    int j = n - 1;
    while (w[j] <= w[i]) j--;

    // Step 3: Swap i and j
    swap(w[i], w[j]);

    // Step 4: Reverse the substring after i
    reverse(w.begin() + i + 1, w.end());

    return w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string w;
        getline(cin, w);
        cout << biggerIsGreater(w) << "\n";
    }

    return 0;
}
