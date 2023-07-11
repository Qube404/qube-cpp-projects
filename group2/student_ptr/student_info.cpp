#include <iostream>

#include "student_info.h"
#include "grad.h"
#include "core.h"

using namespace std;

istream& StudentInfo::read(istream& is) {
    char ch;
    is >> ch;

    if (ch == 'U') {
        cop = new Core(is);
    } else {
        cop = new Grad(is);
    }

    return is;
}
