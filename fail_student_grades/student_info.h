#ifndef GUARD_student_info
#define GUARD_student_info

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::vector<StudentInfo> extract_fails(std::vector<StudentInfo>&);
int output_students(std::ostream&, std::vector<StudentInfo>&, std::string::size_type);

#endif
