#ifndef GUARD_student_info
#define GUARD_student_info

#include <iostream>
#include <string>
#include <vector>

class StudentInfo {
public:
    StudentInfo();
    StudentInfo(std::istream&);

    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);
    double grade() const;
private:
    std::string n;

    double midterm, final;
    std::vector<double> homework;

    int dest, cret, asi, cop;
};

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
