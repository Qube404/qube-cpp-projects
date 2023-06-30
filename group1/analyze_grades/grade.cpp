#include <vector>
#include <stdexcept>

#include "grade.h"
#include "grade_calc.h"
#include "student_info.h"

using namespace std;

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0) {
        throw domain_error("student has done no homework");
    }

    return grade(midterm, final, median(hw));
}

double grade(const StudentInfo& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const StudentInfo& s) {
    return grade(s) < 60;
}

bool pgrade(const StudentInfo& s) {
    return !fgrade(s);
}