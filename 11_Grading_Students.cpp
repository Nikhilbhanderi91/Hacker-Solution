#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<int> gradingStudents(vector<int> grades) {
    for (int &grade : grades) {
        if (grade >= 38) { // Only round if grade is 38 or more
            int nextMultipleOf5 = ((grade / 5) + 1) * 5;
            if (nextMultipleOf5 - grade < 3) {
                grade = nextMultipleOf5;
            }
        }
    }
    return grades;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);
    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);
    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);
        grades[i] = stoi(ltrim(rtrim(grades_item_temp)));
    }

    vector<int> result = gradingStudents(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1) {
            fout << "\n";
        }
    }
    fout << "\n";

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
