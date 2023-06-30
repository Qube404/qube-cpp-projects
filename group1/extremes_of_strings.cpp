#include <algorithm>
#include <cstdint>
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

int main() {
    cout << "Enter any number of strings and end with a EOF: ";
    
    vector<string> group_of_strings;
    string word;

    string smallest_word;
    int smallest_length = 0;

    string largest_word;
    int largest_length = 0;

    while(cin >> word) {
        // We need to set smallest_length to an initial
        // value because no string will ever be smaller
        // then 0.
        if(smallest_length == 0) {
            smallest_length = word.size();
        }

        if(word.size() > largest_length) {
            largest_word = word;
            largest_length = word.size();
        } else if (word.size() < smallest_length) {
            smallest_word = word;
            smallest_length = word.size();
        }
    }

    cout << "Largest Word: " << largest_word << endl; 
    cout << "Smallest Word: " << smallest_word << endl;

    return 0;
}
