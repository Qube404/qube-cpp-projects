#include <cctype>
#include <vector>
#include <string>
#include <iostream>

#include "split_string.h"

using namespace std;

vector<string> split(const string& s) {
    typedef string::size_type string_size;

    vector<string> ret;

    string_size i = 0;
    while (i != s.size()) {

        // Iterate over whitespace, eventually marking
        // i as the start of a word when hitting the 
        // first non-whitespace character.
        while (i != s.size() && isspace(s[i])) {
            ++i;
        }

        // Mark j at the start of the word
        string_size j = i;

        // Keep moving i through the string until
        // hitting a whitespace character aka the
        // end of the string.
        while (j != s.size() && !isspace(s[j])) {
            j++;
        }

        // Push the substring if i and j are not
        // equal, in this loop j can only be
        // above or equal to i.
        if (i != j) {
            ret.push_back(s.substr(i, j - i));

            // Move i up to j so that iteration
            // is not repeated over the same
            // strings.
            i = j;
        }
    }

    return ret;
}
