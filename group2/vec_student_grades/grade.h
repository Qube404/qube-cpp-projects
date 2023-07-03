#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "student_info.h"
#include "vec.h"

double grade(double, double, double);
double grade(double, double, const Vec<double>&);
std::string letter_grade(const StudentInfo& s);

#endif
