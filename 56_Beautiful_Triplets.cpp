#include <bits/stdc++.h>
using namespace std;

int beautifulTriplets(int d, const vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int count = 0;

    for (int x : arr) {
        if (s.count(x + d) && s.count(x + 2 * d)) {
            count++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = beautifulTriplets(d, arr);
    cout << result << "\n";

    return 0;
}
