#ifndef GUARD_student_info
#define GUARD_student_info

#include <iostream>
#include <string>
#include <vector>

class StudentInfo {
public:
    StudentInfo();
    StudentInfo(std::istream&);
    ~StudentInfo() { ++dest; };
    StudentInfo(const StudentInfo& v) { ++cop; };
    StudentInfo& operator=(const StudentInfo& rhs) { ++asi; return *this; };

    std::string name() const { return n; };
    bool valid() const { return !homework.empty(); };
    std::istream& read(std::istream&);
    double grade() const;

    int dest, cret, asi, cop;
private:
    std::string n;

    double midterm, final;
    std::vector<double> homework;
};

bool compare(const StudentInfo&, const StudentInfo&);
std::istream& read(std::istream&, StudentInfo&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
