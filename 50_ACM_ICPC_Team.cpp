#include <bits/stdc++.h>
using namespace std;

vector<int> acmTeam(const vector<string>& topic) {
    int n = topic.size();
    int m = topic[0].size();

    // Preconvert strings to bitsets
    vector<bitset<500>> masks(n); // adjust size if m > 500
    for (int i = 0; i < n; ++i) {
        masks[i] = bitset<500>(topic[i]);
    }

    int maxTopics = 0;
    int teamCount = 0;

    // Compare all pairs
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bitset<500> combined = masks[i] | masks[j];
            int known = combined.count();
            if (known > maxTopics) {
                maxTopics = known;
                teamCount = 1;
            } else if (known == maxTopics) {
                teamCount++;
            }
        }
    }

    return {maxTopics, teamCount};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> topic(n);
    for (int i = 0; i < n; ++i) {
        cin >> topic[i];
    }

    vector<int> result = acmTeam(topic);
    cout << result[0] << "\n" << result[1] << "\n";
    return 0;
}
