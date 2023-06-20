#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::string;
using std::vector;

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

int main() {
    cout << "Type words separated by whitespace and ended with EOF: ";

    // I don't know how to use more complex data structures yet so I'm
    // defining two vectors with matching values that I'm manually
    // keeping synced.
    vector<string> distinct_words;
    vector<int> num_of_distincts;
    string word;

    // Stops running when cin detects some sort of end point.
    while(cin >> word) {
        int index = contains_string(distinct_words, word);

        // If index does not equal -1 then we are just adding
        // to the correct index of the number of words vectors
        // since it already exists.
        if(index != -1) {
            ++num_of_distincts[index]; 

        // If it doesn't exist we push a new word into the
        // distinct words vector and number vector with the
        // distinct word and 1 respectively.
        } else {
            distinct_words.push_back(word);
            num_of_distincts.push_back(1);
        }
    }

    // Printing the words and number vector in a readable format.
    typedef vector<string>::size_type vec_sz;
    for (vec_sz i = 0; i != distinct_words.size(); i++) {
        cout << distinct_words[i] << ": " << num_of_distincts[i] << endl;
    }

    // Only printing a newline if there were no words entered to avoid
    // a double newline formed by this and the pretty printing loop.
    if (distinct_words.size() == 0) {
        cout << endl;
    }

    return 0;
}
