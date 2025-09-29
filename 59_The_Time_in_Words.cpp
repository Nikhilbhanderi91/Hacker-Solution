#include <bits/stdc++.h>
using namespace std;

string timeInWords(int h, int m) {
    string numbers[] = { "zero", "one", "two", "three", "four", "five", "six",
                         "seven", "eight", "nine", "ten", "eleven", "twelve",
                         "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                         "eighteen", "nineteen", "twenty", "twenty one", "twenty two",
                         "twenty three", "twenty four", "twenty five", "twenty six",
                         "twenty seven", "twenty eight", "twenty nine" };

    if (m == 0) return numbers[h] + " o' clock";
    if (m == 15) return "quarter past " + numbers[h];
    if (m == 30) return "half past " + numbers[h];
    if (m == 45) return "quarter to " + numbers[(h % 12) + 1];

    if (m < 30) {
        return (m == 1 ? "one minute past " : numbers[m] + " minutes past ") + numbers[h];
    } else {
        int remaining = 60 - m;
        return (remaining == 1 ? "one minute to " : numbers[remaining] + " minutes to ") + numbers[(h % 12) + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m;
    cin >> h >> m;

    cout << timeInWords(h, m) << "\n";
    return 0;
}
