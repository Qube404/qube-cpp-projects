#include "student_info.h"

using namespace std;

StudentInfo::StudentInfo(): midterm(0), final(0) {}
StudentInfo::StudentInfo(istream& is) { read(is); }

bool compare(const StudentInfo& x, const StudentInfo& y) {
    return x.name() < y.name();
}

istream& StudentInfo::read(istream& is) {
    is >> n >> midterm >> final;

    read_hw(is, homework);
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
