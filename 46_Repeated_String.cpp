#include <bits/stdc++.h>
using namespace std;

/*
 * Count how many 'a' appear in the first n characters
 * of infinite repetition of s.
 * Time: O(|s|)
 * Space: O(1)
 */
long long repeatedString(const string &s, long long n) {
    long long len = s.size();

    // Count 'a' in one copy of s
    long long countA = 0;
    for (char c : s) {
        if (c == 'a') countA++;
    }

    // How many full copies fit in n
    long long fullRepeats = n / len;
    long long total = countA * fullRepeats;

    // Count 'a' in the leftover part
    long long remainder = n % len;
    for (long long i = 0; i < remainder; i++) {
        if (s[i] == 'a') total++;
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    long long n;
    cin >> s >> n;

    cout << repeatedString(s, n) << "\n";
    return 0;
}
