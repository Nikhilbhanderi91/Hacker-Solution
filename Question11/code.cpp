#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> memo;
unordered_set<string> dict;
vector<string> solution;

bool dfs(string &s, int index, vector<string> &passwords, vector<string> &path) {
    if ((size_t)index == s.length()) {
        solution = path;
        return true;
    }

    string remaining = s.substr(index);
    if (memo.count(remaining)) return false;

    for (const string &word : passwords) {
        int len = word.length();
        if (s.substr(index, len) == word) {
            path.push_back(word);
            if (dfs(s, index + len, passwords, path)) {
                return true;
            }
            path.pop_back();
        }
    }

    memo[remaining] = false;
    return false;
}

string passwordCracker(vector<string> passwords, string loginAttempt) {
    memo.clear();
    dict.clear();
    solution.clear();

    for (const string &word : passwords) {
        dict.insert(word);
    }

    vector<string> path;
    if (dfs(loginAttempt, 0, passwords, path)) {
        return accumulate(solution.begin(), solution.end(), string(),
                          [](const string &a, const string &b) {
                              return a.empty() ? b : a + " " + b;
                          });
    } else {
        return "WRONG PASSWORD";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> passwords(n);
        for (int i = 0; i < n; ++i) {
            cin >> passwords[i];
        }

        string loginAttempt;
        cin >> loginAttempt;

        cout << passwordCracker(passwords, loginAttempt) << endl;
    }
    return 0;
}
