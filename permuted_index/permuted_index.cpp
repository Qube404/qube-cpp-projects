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
    string s = ' ' + str;
    vector<PermutedIndex> ret;

    string working_str;

    PermutedIndex working_perm;
    working_perm.line1 = str;
    working_perm.line2 = "";

    // Push all rotations of a string into rotations
    // vector
    ret.push_back(working_perm);
    for (str_sz i = 1, spaces = 0; i != s.size(); i++) {
        if (s[i] != ' ') {
            continue;
        }

        working_str.clear();
        str_sz size = 0;

        str_sz start = i;
        for (str_sz j = 0; j != s.size(); j++) {
            if (start == s.size()) {
                start = 0;
                size = working_str.size();
                working_perm.line1 = working_str.substr(1, size);
                working_str.clear();
            } 

            working_str += s[start];
            ++start;
        }

        size = working_str.size();
        working_perm.line2 = working_str.substr(1, size);

        ++spaces;
        ret.push_back(working_perm);
    }

    return ret;
}

bool compare_permuted_indexes(const PermutedIndex &p1, const PermutedIndex &p2) {
    return str_to_lower(p1.line1) < str_to_lower(p2.line1);
}
