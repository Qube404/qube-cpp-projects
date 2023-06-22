#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

int main() {
    // Generate rotations of strings
    vector<PermutedIndex> rotations = rotate_string("zeta charlie alpha beta");

    // Sort them alphabetically
    sort(rotations.begin(), rotations.end(), compare_permuted_indexes);

    for (vector<string>::size_type i = 0; i != rotations.size(); i++) {
        cout << rotations[i].line << endl;
    }
    
    return 0;
}
