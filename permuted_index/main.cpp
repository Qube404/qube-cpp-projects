#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

int main() {
    string input = "The quick brown fox\njumped over the fence";

    // Generate rotations of strings
    vector<PermutedIndex> rotations = rotate_string(input);

    // Sort them alphabetically
    sort(rotations.begin(), rotations.end(), compare_permuted_indexes);

    str_sz line1 = 0;
    perm_vec_sz max_size = 0;
    for (perm_vec_sz i = 0; i != rotations.size(); i++) {
        line1 = rotations[i].line1.size();
        max_size = max(max_size, line1);
    }

    for (perm_vec_sz i = 0; i != rotations.size(); i++) {
        line1 = rotations[i].line1.size();

        cout 
            << string(max_size - line1, ' ') << rotations[i].line1 
            << "    " 
            << rotations[i].line2 << endl;
    }

    return 0;
}
