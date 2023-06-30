#ifndef GUARD_distinct_word_counter_h
#define GUARD_distinct_word_counter_h

#include <vector>
#include <string>
#include <iostream>

struct DistinctWords {
    std::vector<std::string> words;
    std::vector<int> nums;
};

DistinctWords distinct_word_counter(std::istream&);

#endif
