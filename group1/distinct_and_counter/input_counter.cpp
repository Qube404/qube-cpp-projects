#include <iostream>

#include "distinct_word_counter.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

int main() {
    cout << "Enter any number of words: ";
    DistinctWords distinct_words = distinct_word_counter(cin);

    typedef vector<string>::size_type vec_sz;

    vec_sz size = distinct_words
        .words
        .size();
    int num_of_words = 0;

    for(vec_sz i = 0; i != size; i++) {
        num_of_words += distinct_words.nums[i];
    }

    cout << "Words: " << num_of_words << endl;

    return 0;
}
