#include <bits/stdc++.h>
#include <cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.

  INPUT-FORMAT:
  The first line contains a single interger n, the size of the vector a:
  The second line contains n space-seperated intergers, each an a[i]

 */

int pickingNumbers(vector<int> a) {

    // sort the vector (bubblesort)
    for (int i = 0; i < a.size(); i++) {
        for (int y = 0; y < a.size()-1; y++) {
            if (a[y] > a[y+1]) {
                int tmp = a[y+1];
                a[y+1] = a[y];
                a[y] = tmp;
            }
        }
    }
        
    if (a.size() == 1) return 1;

    int max_range = 0;
    int tmp_max_range = 0;
    int tmp_cmp_val;
    bool flow = false;
    for (int i = 0; i < a.size()-1; i++) {
        // flow = criteria currently applies to the current number
        if (flow) {
            if (abs(tmp_cmp_val - a[i+1]) <= 1) {
                tmp_max_range++;
            } else {
                if (tmp_max_range > max_range) {
                    max_range = tmp_max_range;
                }  
                tmp_max_range = 0;
                flow = false;
            }
        }
        // new flow-status?
        else {
            if (abs(a[i] - a[i+1]) <= 1) {
                tmp_cmp_val = a[i];
                flow = true;
                tmp_max_range += 2;
            }
        }
    }
    if (tmp_max_range > max_range) max_range = tmp_max_range;
    return max_range;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

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

