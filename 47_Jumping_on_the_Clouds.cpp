#include <bits/stdc++.h>
using namespace std;

/*
 * Compute minimum jumps to reach last cloud
 * Time: O(n)
 * Space: O(1)
 */
int jumpingOnClouds(const vector<int> &c) {
    int n = c.size();
    int jumps = 0;
    int i = 0;

    while (i < n - 1) {
        if (i + 2 < n && c[i + 2] == 0) {
            i += 2;
        } else {
            i += 1;
        }
        jumps++;
    }
    return jumps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    cout << jumpingOnClouds(c) << "\n";
    return 0;
}
