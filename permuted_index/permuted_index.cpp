#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

typedef vector<string>::size_type vec_sz;
typedef string::size_type str_sz;

vector<PermutedIndex> rotate_string(const string& s) {
    vector<PermutedIndex> ret;
    vector<string> split_str = split(s);

    string working_str;
    PermutedIndex working_perm;

    // Push all rotations of a string into rotations
    // vector
    for (vec_sz i = 0; i != split_str.size(); i++) {
        working_str.clear();

        vec_sz start = i;
        str_sz start_index = 0;
        for (vec_sz j = 0; j != split_str.size(); j++) {
            if (start == split_str.size()) {
                start = 0;
            } 

            working_str += split_str[start] + " ";
            ++start;
        }

        working_perm.line = working_str;
        working_perm.start = 0;
        ret.push_back(working_perm);
    }

    return ret;
}

int main() {
    vector<string> str = rotate_string("test read my balls");

    for (vector<string>::size_type i = 0; i != str.size(); i++) {
        cout << str[i] << endl;
    }
}
