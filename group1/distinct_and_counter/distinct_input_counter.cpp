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

    for(vec_sz i = 0; i != size; i++) {
        cout << distinct_words.words[i] << ": " << distinct_words.nums[i] << endl;
    }

    return 0;
}
