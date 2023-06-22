#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

typedef vector<string>::size_type vec_sz;
typedef string::size_type str_sz;

vector<PermutedIndex> rotate_string(const string& str) {
    string s = str + ' ';
    vector<PermutedIndex> ret;

    string working_str;
    PermutedIndex working_perm;

    // Push all rotations of a string into rotations
    // vector
    for (vec_sz i = 0; i != s.size(); i++) {
        if (s[i] == ' ') {
            working_str.clear();

            vec_sz start = i;
            for (vec_sz j = 0; j != s.size(); j++) {
                if (start == s.size()) {
                    start = 0;
                } 

                working_str += s[start];
                ++start;
            }

            string::size_type sz = working_str.size();
            working_perm.line = working_str.substr(1, sz);
            working_perm.start = 0;

            ret.push_back(working_perm);
        }
    }

    return ret;
}
