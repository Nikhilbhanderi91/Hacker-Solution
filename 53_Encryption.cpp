#include <bits/stdc++.h>
using namespace std;

string encryption(const string &s) {
    string cleaned;
    for (char c : s) {
        if (c != ' ') cleaned += c;
    }

    int L = cleaned.size();
    int rows = floor(sqrt(L));
    int cols = ceil(sqrt(L));
    if (rows * cols < L) rows++;

    string result;
    for (int c = 0; c < cols; c++) {
        if (!result.empty()) result += ' ';
        for (int r = 0; r < rows; r++) {
            int idx = r * cols + c;
            if (idx < L) result += cleaned[idx];
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    cout << encryption(s) << "\n";
    return 0;
}
