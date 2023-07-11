#include <iostream>

#include "student_info.h"
#include "grad.h"
#include "core.h"

using namespace std;

istream& StudentInfo::read(istream& is) {
    delete cop;

    char ch;
    is >> ch;

    if (ch == 'U') {
        cop = new Core(is);
    } else {
        cop = new Grad(is);
    }

    return is;
}

StudentInfo::StudentInfo(const StudentInfo& s): cop(0) {
    if (s.cop) {
        cop = s.cop->clone();
    } 
}

StudentInfo& StudentInfo::operator=(const StudentInfo& s) {
    if (&s != this) {
        delete cop;
        if (s.cop) {
            cop = s.cop->clone();
        } else {
            cop = 0;
        }
    }

    return *this;
}
