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

// The collection type to use for StudentInfo operations
typedef std::vector<StudentInfo> collection;

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
std::istream& read_hw(std::istream&, std::vector<double>&);
collection extract_fails(collection&);
int output_students(std::ostream&, collection&, std::string::size_type);

#endif
