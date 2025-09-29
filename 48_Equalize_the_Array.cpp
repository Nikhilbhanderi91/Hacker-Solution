#include <bits/stdc++.h>
using namespace std;

/*
 * Compute minimum deletions to make array equal
 * Time: O(n)
 * Space: O(1) if value range is small (like 1..100)
 */
int equalizeArray(const vector<int>& arr) {
    // Adjust size if constraints larger than 100
    array<int, 101> freq{};  // zero-initialized
    int maxFreq = 0;

    for (int val : arr) {
        freq[val]++;
        if (freq[val] > maxFreq) {
            maxFreq = freq[val];
        }
    }

    return (int)arr.size() - maxFreq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << equalizeArray(arr) << "\n";
    return 0;
}
