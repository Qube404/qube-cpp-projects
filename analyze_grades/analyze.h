#include <vector>
#include <string>
#include <iostream>

#include "student_info.h"

double grade_aux(const StudentInfo&);
double average_grade(const StudentInfo&);
double optimistic_median(const StudentInfo&);

double analyze_students(const std::vector<StudentInfo>&, double transfunc(const StudentInfo&));

void write_analysis(
    std::ostream&, 
    const std::string&,
    double analysis(const StudentInfo&),
    const std::vector<StudentInfo>&,
    const std::vector<StudentInfo>&
);
