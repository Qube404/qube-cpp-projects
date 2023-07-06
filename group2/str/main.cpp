#include <iostream>

#include "str.h"
#include "vec.h"

using namespace std;

int main() {
    char thing[] = {'1', '2'};
    Str my_str = thing;
    cout << my_str << endl;

    char *my_chars = my_str.c_str();
    cout << my_chars << endl;

    char *my_chars2 = my_str.c_data();
    cout << my_chars << endl;

    char copy_chars[10]{};
    my_str.copy(copy_chars, 9);
    cout << copy_chars << endl;

    return 0;
}
