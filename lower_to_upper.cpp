#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    string input;
    string s;
    while (getline(cin, input)) {
        s += input;
    }

    string upper;
    cout << endl << endl;
    for (string::size_type i = 0; i != s.size(); i++) {
        upper += toupper(s[i]);
    }
    cout << upper << endl;

    return 0;
}
