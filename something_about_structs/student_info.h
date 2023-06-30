#ifndef GUARD_student_info
#define GUARD_student_info

#include <iostream>
#include <istream>
#include <string>
#include <vector>

class StudentInfo {
public:
    StudentInfo();
    StudentInfo(std::istream&);

    double grade() const;
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);
    std::string name() const { return n; };

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const StudentInfo&, const StudentInfo&);

#endif
