#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>

#include "core.h"
#include "handle.h"

class StudentInfo {
public:
    StudentInfo() {}
    StudentInfo(std::istream& is) { read(is); }

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

    bool valid() const {
        if (cop) {
            return cop->valid();
        } else {
            return false;
        }
    }

    std::string letter_grade() const {
        if (cop) {
            return cop->letter_grade();
        } else {
            throw std::runtime_error("unitialized Student");
        }
    }

    static bool compare(const StudentInfo& s1, const StudentInfo& s2) {
        return s1.name() < s2.name();
    }

private:
    Handle<Core> cop;
};
