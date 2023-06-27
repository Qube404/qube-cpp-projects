#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>

#include "student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const StudentInfo&);

bool fgrade(const StudentInfo&);
bool pgrade(const StudentInfo&);

#endif
