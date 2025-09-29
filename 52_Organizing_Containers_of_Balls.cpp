#include <bits/stdc++.h>
using namespace std;

string organizingContainers(vector<vector<int>>& container) {
    int n = container.size();
    vector<long long> rowSum(n, 0), colSum(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rowSum[i] += container[i][j];
            colSum[j] += container[i][j];
        }
    }

    sort(rowSum.begin(), rowSum.end());
    sort(colSum.begin(), colSum.end());

    return (rowSum == colSum) ? "Possible" : "Impossible";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<vector<int>> container(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> container[i][j];

        cout << organizingContainers(container) << "\n";
    }
    return 0;
}
