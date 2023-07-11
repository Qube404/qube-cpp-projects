#ifndef GUARD_StudentInfo
#define GUARD_StudentInfo

#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>

#include "core.h"
#include "ptr.h"

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

    void regrade(double final, double thesis) {
        cop.make_unique();

        if (cop) {
            // Does nothing for now since I haven't implemented regrade
            // core and grad
            //
            //cop->regrade(final, thesis);
        } else {
            throw std::runtime_error("regrade of unknown Student");
        }
    }

private:
    Ptr<Core> cop;
};

#endif
