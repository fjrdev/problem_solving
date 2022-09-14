#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    char am_pm = s[s.size()-2];
    s.erase(s.end()-2, s.end());
    
    if (am_pm == 'A') {
        string hour = s;
        hour.erase(2, 9);
        if (hour == "12") {
            string zero = "00";
            return zero.append(s.erase(0,2));
        }
        return s;
    } else {
        // add 12 to hour-counter
        string tmp_hour = s;
        if (tmp_hour.erase(2,9) == "12") {
            return s.erase(8,9);
        }
        string tmp = s;
        tmp.erase(tmp.begin()+2, tmp.end());
        int new_hour = stoi(tmp)+12;
        s.erase(s.begin(), s.begin()+2);
        return to_string(new_hour) + s;
    }
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

