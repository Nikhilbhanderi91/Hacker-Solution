#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hourStr = s.substr(0, 2);
    string minSec = s.substr(2, 6); // ":mm:ss"
    string period = s.substr(8, 2); // "AM" or "PM"
    
    int hour = stoi(hourStr);

    if (period == "AM") {
        if (hour == 12)
            hour = 0;
    } else if (period == "PM") {
        if (hour != 12)
            hour += 12;
    }

    // Format the hour with leading 0 if needed
    stringstream ss;
    ss << setfill('0') << setw(2) << hour << minSec;
    
    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
