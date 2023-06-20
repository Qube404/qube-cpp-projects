#include <vector>
#include <string>
#include <iostream>

#include "distinct_word_counter.h"

using std::vector;
using std::string;
using std::istream;

int contains_string(vector<string> string_vec, string word) {
    // Error case where there are no words in the vec yet.
    if (string_vec.size() == 0) {
        return -1;
    }

    // If the string vector contains the string word return
    // the index it is contained at in the vector.
    for(int i = 0; i != string_vec.size(); i++) {
        if(string_vec[i] == word) {
            return i;
        }
    }

    // Return -1 by default meaning no matching words
    // were found in the vector.
    return -1;
}

DistinctWords distinct_word_counter(istream& word_stream) {
    DistinctWords distinct_words;
    string word;

    while(word_stream >> word) {
        int word_index = contains_string(distinct_words.words, word);

        if(word_index != -1) {
            ++distinct_words.nums[word_index];
        } else {
            distinct_words
                .words
                .push_back(word);

            distinct_words
                .nums
                .push_back(1);
        }
    }

    return distinct_words;
}
