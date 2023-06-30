#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool has_ascenders(string s) {
    string ascenders = "bdfhklt";

    for (
        string::const_iterator iter = s.begin();
        iter != s.end();
        iter++
    ) {
        for (
            string::const_iterator asc = ascenders.begin();
            iter != ascenders.end();
            asc++
        ) {
            if (*iter == *asc) {
                return true;
            }
        }
    }

    return false;
}

bool has_descenders(string s) {
    string descenders = "gjpqy";

    for (
        string::const_iterator iter = s.begin();
        iter != s.end();
        iter++
    ) {
        for (
            string::const_iterator desc = descenders.begin();
            iter != descenders.end();
            desc++
        ) {
            if (*iter == *desc) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string input;
    vector<string> s;
    while (getline(cin, input)) {
        s.push_back(input);
    }

    for (
        vector<string>::const_iterator iter = s.begin();
        iter != s.end();
        iter++
    ) {
        if (has_ascenders(*iter) && has_descenders(*iter)) {
            cout << "Has ascenders and descenders: ";
        } else if (has_ascenders(*iter)) {
            cout << "Has ascenders: ";
        } else if (has_descenders(*iter)) {
            cout << "Has descenders: ";
        } else {
            cout << "Has neither: ";
        }

        cout << *iter << endl;
    }
}
