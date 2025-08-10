#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main() {
    string first_multiple_input;
    getline(cin, first_multiple_input);
    vector<string> first_multiple = split(rtrim(first_multiple_input));
    int s = stoi(first_multiple[0]);
    int t = stoi(first_multiple[1]);

    string second_multiple_input;
    getline(cin, second_multiple_input);
    vector<string> second_multiple = split(rtrim(second_multiple_input));
    int a = stoi(second_multiple[0]);
    int b = stoi(second_multiple[1]);

    string third_multiple_input;
    getline(cin, third_multiple_input);
    vector<string> third_multiple = split(rtrim(third_multiple_input));
    int m = stoi(third_multiple[0]);
    int n = stoi(third_multiple[1]);

    string apples_input;
    getline(cin, apples_input);
    vector<string> apples_temp = split(rtrim(apples_input));
    vector<int> apples(m);
    for (int i = 0; i < m; i++) {
        apples[i] = stoi(apples_temp[i]);
    }

    string oranges_input;
    getline(cin, oranges_input);
    vector<string> oranges_temp = split(rtrim(oranges_input));
    vector<int> oranges(n);
    for (int i = 0; i < n; i++) {
        oranges[i] = stoi(oranges_temp[i]);
    }

    int appleCount = 0, orangeCount = 0;

    // Count apples that fall on the house
    for (int apple : apples) {
        int landingPosition = a + apple;
        if (landingPosition >= s && landingPosition <= t) {
            appleCount++;
        }
    }

    // Count oranges that fall on the house
    for (int orange : oranges) {
        int landingPosition = b + orange;
        if (landingPosition >= s && landingPosition <= t) {
            orangeCount++;
        }
    }

    cout << appleCount << "\n" << orangeCount << "\n";
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
