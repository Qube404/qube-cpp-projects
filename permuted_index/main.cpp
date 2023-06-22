#include <vector>
#include <string>
#include <iostream>

#include "permuted_index.h"
#include "split_string.h"

using namespace std;

int main() {
    vector<PermutedIndex> rotations = rotate_string("rotate this string please");

    for (vector<string>::size_type i = 0; i != rotations.size(); i++) {
        cout << rotations[i].line << endl;
    }
}
