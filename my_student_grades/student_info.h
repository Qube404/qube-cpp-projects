#ifndef GUARD_student_info
#define GUARD_student_info

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo {
    std::string name;
    double final_grade;
};

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
