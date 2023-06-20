#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::to_string;
using std::cout;
using std::setw;
using std::endl;

typedef string::size_type str_sz;

str_sz sizeof_double_to_string(double val, int precision) {
    return std::to_string((int) val).size() + precision;
}

int main() {
    int num = 100;
    int double_prec = 3;

    str_sz max_num_len = sizeof_double_to_string(num - 1, double_prec);
    str_sz max_sqr_len = sizeof_double_to_string((num - 1) * (num - 1), double_prec);

    str_sz max_len = max_num_len + max_sqr_len + double_prec - 1; 

    for(double i = 0; i != num; i++) {
        string num = std::to_string(i) + ":";
        string square = to_string(i * i);

        string::size_type num_len = sizeof_double_to_string(i, double_prec);

        cout 
            // Constants of entire output
            << std::left << std::setprecision(2) << std::fixed

            // First number and colon
            << setw(num_len) << i << ":" 

            // Spacing between numbers
            << string(max_num_len - num_len + 1, ' ') 

            // Squared number
            << setw(max_sqr_len) << i * i

            // Newline for next loop iteration
            << endl;
    }
}
