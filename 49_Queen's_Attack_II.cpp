#include <bits/stdc++.h>
using namespace std;

long queensAttack(int n, int k, int r_q, int c_q, const vector<pair<int,int>>& obstacles) {
    // max steps in each direction without obstacles
    long up = n - r_q;
    long down = r_q - 1;
    long right = n - c_q;
    long left = c_q - 1;
    long up_right = min((long)n - r_q, (long)n - c_q);
    long up_left = min((long)n - r_q, (long)c_q - 1);
    long down_right = min((long)r_q - 1, (long)n - c_q);
    long down_left = min((long)r_q - 1, (long)c_q - 1);

    // adjust based on obstacles
    for (auto [r_o, c_o] : obstacles) {
        if (c_o == c_q) { // same column
            if (r_o > r_q) up = min(up, (long)r_o - r_q - 1);
            else down = min(down, (long)r_q - r_o - 1);
        } 
        else if (r_o == r_q) { // same row
            if (c_o > c_q) right = min(right, (long)c_o - c_q - 1);
            else left = min(left, (long)c_q - c_o - 1);
        } 
        else if (abs(r_o - r_q) == abs(c_o - c_q)) { // diagonal
            if (r_o > r_q && c_o > c_q)
                up_right = min(up_right, (long)r_o - r_q - 1);
            else if (r_o > r_q && c_o < c_q)
                up_left = min(up_left, (long)r_o - r_q - 1);
            else if (r_o < r_q && c_o > c_q)
                down_right = min(down_right, (long)r_q - r_o - 1);
            else if (r_o < r_q && c_o < c_q)
                down_left = min(down_left, (long)r_q - r_o - 1);
        }
    }

    return up + down + left + right + up_right + up_left + down_right + down_left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<pair<int,int>> obstacles(k);
    for (int i = 0; i < k; ++i) {
        cin >> obstacles[i].first >> obstacles[i].second;
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << "\n";
    return 0;
}
