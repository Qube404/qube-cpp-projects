#include <iostream>

#include "student_info.h"
#include "grade.h"

using namespace std;

StudentInfo::StudentInfo(): midterm(0), final(0) {}

StudentInfo::StudentInfo(istream& is) { read(is); }

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();

        double x;
        while (in >> x) {
            hw.push_back(x);
        }

        in.clear();
    }

    return in;
}

istream& StudentInfo::read(istream& in) {
    in >> n >> midterm >> final; 

    read_hw(in, homework);
    g = ::grade(midterm, final, homework);

    return in;
}

bool compare(const StudentInfo& x, const StudentInfo& y) {
    return x.name() < y.name();
}

