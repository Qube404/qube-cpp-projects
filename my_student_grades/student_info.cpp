#include "stdexcept"

#include "student_info.h"
#include "median.h"
#include "grade.h"

using namespace std;

bool compare(const StudentInfo& x, const StudentInfo& y) {
    return x.name < y.name;
}

istream& read(istream& is, StudentInfo& s) {
    double midterm, final;
    vector<double> homework;

    is >> s.name >> midterm >> final;

    read_hw(is, homework);

    if (homework.size() == 0) {
        throw domain_error("student has done no homework");
    }

    s.final_grade = grade(midterm, final, median(homework));

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
