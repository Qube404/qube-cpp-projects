#include <cctype>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> split(const string& s) {
    typedef string::size_type string_size;

    vector<string> ret;

    string_size i = 0;
    while (i != s.size()) {

        while (i != s.size() && isspace(s[i])) {
            ++i;
        }

        string_size j = i;

        while (j != s.size() && !isspace(s[j])) {
            j++;

            if (i != j) {
                ret.push_back(s.substr(i, j - i));
                i = j;
            }
        }
    }

    return ret;
}
