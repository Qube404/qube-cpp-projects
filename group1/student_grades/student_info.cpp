#include "student_info.h"

using std::istream; using std::vector;

bool compare(const StudentInfo& x, const StudentInfo& y) {
    return x.name < y.name;
}

istream& read(istream& is, StudentInfo& s) {
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}

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
