#ifndef GUARD_student_info
#define GUARD_student_info

#include <iostream>
#include <string>
#include <vector>
#include <list>

struct StudentInfo {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::list<StudentInfo> extract_fails(std::list<StudentInfo>&);
int output_students(std::ostream&, std::list<StudentInfo>&, std::string::size_type);

#endif
