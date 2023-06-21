#include <string>
#include <iostream>

#include "split_string.h"

using namespace std;

int main() {
    string s;

    while (getline(cin, s)) {
        vector<string> v = split(s);

        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }

    return 0;
}
