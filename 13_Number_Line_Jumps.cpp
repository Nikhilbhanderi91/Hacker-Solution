#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string kangaroo(int x1, int v1, int x2, int v2) {
    // If v1 == v2, they will never meet unless they start together
    if (v1 == v2) {
        return (x1 == x2) ? "YES" : "NO";
    }
    // Check if they meet: (x2 - x1) % (v1 - v2) == 0 and land on same spot
    if ((x2 - x1) % (v1 - v2) == 0 && (x2 - x1) / (v1 - v2) < 0) {
        return "NO";
    }
    return ((x2 - x1) % (v1 - v2) == 0 && (v1 > v2 && x1 < x2) || (v2 > v1 && x2 < x1)) ? "YES" : "NO";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input;
    getline(cin, first_multiple_input);
    vector<string> first_multiple = split(rtrim(first_multiple_input));

    int x1 = stoi(first_multiple[0]);
    int v1 = stoi(first_multiple[1]);
    int x2 = stoi(first_multiple[2]);
    int v2 = stoi(first_multiple[3]);

    string result = kangaroo(x1, v1, x2, v2);

    fout << result << "\n";
    fout.close();

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
    string::size_type start = 0, end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
