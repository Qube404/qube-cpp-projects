#include <iterator>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "analyze.h"
#include "student_info.h"
#include "grade.h"
#include "grade_calc.h"

using namespace std;

double grade_aux(const StudentInfo &s) {
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double average_grade(const StudentInfo& s) {
    return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const StudentInfo& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty()) {
        return grade(s.midterm, s.final, 0);
    } else {
        return grade(s.midterm, s.final, median(nonzero));
    }
}

double analyze_students(const vector<StudentInfo>& students, double transfunc(const StudentInfo&)) {
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), transfunc);

    return median(grades);
}

void write_analysis(
    ostream& out, 
    const string& name,
    double transfunc(const StudentInfo&),
    const vector<StudentInfo>& did,
    const vector<StudentInfo>& didnt
) {
    out << name << ": median(did) == " << analyze_students(did, transfunc) <<  
                   ", median(didnt) == " << analyze_students(didnt, transfunc) << endl;
}
