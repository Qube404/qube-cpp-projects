#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

int main() {
    string input = "The quick brown fox";

    // Generate rotations of strings
    vector<PermutedIndex> rotations = rotate_string(input);

    // Sort them alphabetically
    sort(rotations.begin(), rotations.end(), compare_permuted_indexes);

    perm_vec_sz max_size = 0;
    for (perm_vec_sz i = 0; i != rotations.size(); i++) {
        max_size = max(max_size, rotations[i].line2.size());
    }

    str_sz width = 0;
    /*for (perm_vec_sz i = 0; i != rotations.size(); i++) {
        width = max_size - rotations[i].line2.size();
        cout << string(width, ' ') << rotations[i].line2 << "    " << rotations[i].line1 << endl;
    }*/

    return 0;
}
