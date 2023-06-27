#include <vector>
#include <string>
#include <iostream>

#include "student_info.h"

double grade_aux(const StudentInfo&);
double average_grade(const StudentInfo&);
double optimistic_median(const StudentInfo&);

double median_analysis(const std::vector<StudentInfo>&);
double average_analysis(const std::vector<StudentInfo>&);
double optimistic_median_analysis(const std::vector<StudentInfo>&);

void write_analysis(
    std::ostream&, 
    const std::string&,
    double analysis(const std::vector<StudentInfo>&),
    const std::vector<StudentInfo>&,
    const std::vector<StudentInfo>&
);
