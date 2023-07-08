#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>

#include "core.h"

class StudentInfo {
public:
    StudentInfo(): cop(0) {}
    StudentInfo(std::istream& is): cop(0) { read(is); }
    StudentInfo(const StudentInfo&);
    StudentInfo& operator=(const StudentInfo&);
    ~StudentInfo() { delete cop; }

    std::istream& read(std::istream&);

    std::string name() const {
        if (cop) {
            return cop->name();
        } else {
            throw std::runtime_error("unitialized Student");
        }
    }

    double grade() const {
        if (cop) {
            return cop->grade();
        } else {
            throw std::runtime_error("unitialized Student");
        }
    }

    static bool compare(const StudentInfo& s1, const StudentInfo& s2) {
        return s1.name() < s2.name();
    }

private:
    Core *cop;
};
