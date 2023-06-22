#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

typedef vector<string>::size_type str_vec_sz;
typedef vector<PermutedIndex>::size_type perm_vec_sz;
typedef string::size_type str_sz;

vector<PermutedIndex> rotate_string(const string& str) {
    string s = ' ' + str;
    vector<PermutedIndex> ret;

    string working_str;

    PermutedIndex working_perm;

    // Push all rotations of a string into rotations
    // vector
    for (str_sz i, spaces = 0; i != s.size(); i++) {
        if (s[i] == ' ') {
            working_str.clear();

            str_sz start = i;
            for (str_sz j = 0; j != s.size(); j++) {
                if (start == s.size()) {
                    start = 0;
                } 

                working_str += s[start];
                ++start;
            }

            str_sz sz = working_str.size();
            working_perm.line = working_str.substr(1, sz);
            working_perm.start = spaces;

            ++spaces;
            ret.push_back(working_perm);
        }
    }

    return ret;
}

bool compare_permuted_indexes(const PermutedIndex &p1, const PermutedIndex &p2) {
    return p1.line < p2.line;
}
