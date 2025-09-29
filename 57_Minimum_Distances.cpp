#include <bits/stdc++.h>
using namespace std;

int minimumDistances(const vector<int>& a) {
    unordered_map<int, int> lastIndex;  // store last seen index of each number
    int minDist = INT_MAX;

    for (int i = 0; i < a.size(); i++) {
        if (lastIndex.count(a[i])) {
            minDist = min(minDist, i - lastIndex[a[i]]);
        }
        lastIndex[a[i]] = i;
    }

    return (minDist == INT_MAX) ? -1 : minDist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << minimumDistances(a) << "\n";

    return 0;
}
