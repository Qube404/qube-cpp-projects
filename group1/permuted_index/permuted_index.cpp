#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

string str_to_lower(string s) {
    for (str_sz i = 0; i != s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    return s;
}

vector<PermutedIndex> rotate_string(const string& str) {
    stringstream st(str);
    vector<PermutedIndex> ret;
    PermutedIndex working_perm;

    // Push all rotations of a string into rotations
    // vector
    string s = "";
    while (getline(st, s)) {
        working_perm.line1 = "";
        working_perm.line2 = s;
        ret.push_back(working_perm);

        for (str_sz i = 1; i != s.size(); i++) {
            if (s[i] != ' ') {
                continue;
            }

            working_perm.line1 = s.substr(0, i);
            working_perm.line2 = s.substr(i + 1, s.size());

            ret.push_back(working_perm);
        }
    }

    return ret;
}

bool compare_permuted_indexes(const PermutedIndex &p1, const PermutedIndex &p2) {
    return str_to_lower(p1.line2) < str_to_lower(p2.line2);
}
