#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> s;
    string input;
    while (getline(cin, input)) {
        s.push_back(input);
    }

    string s_rev;
    vector<string> palindromes;
    for (vector<string>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
        s_rev.resize(iter->size());
        reverse_copy(iter->begin(), iter->end(), s_rev.begin());

        if (*iter == s_rev) {
            palindromes.push_back(*iter);
        }
    }

    string longest;
    for (
        vector<string>::const_iterator iter = palindromes.begin();
        iter != palindromes.end();
        iter++
    ) {
        if (iter->size() > longest.size()) {
            longest = *iter;
        }
    }

    cout << endl;
    cout << "Longest: " << longest << endl;
    for (vector<string>::const_iterator iter = palindromes.begin(); iter != palindromes.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
