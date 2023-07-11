#ifndef GUARD_core
#define GUARD_core

#include <iostream>
#include <string>
#include <vector>

class Core {
friend class StudentInfo;

public:
    Core(): midterm(0), final(0) {}

    Core(std::istream& is) { 
        read(is); 
    }

    virtual ~Core() {}

    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    std::string letter_grade() const;
    bool valid() const;

protected:
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
    virtual Core* clone() const { return new Core(*this); }

private:
    std::string n;
};

bool compare(const Core& c1, const Core& c2);
bool compare_Core_pointers(const Core* c1, const Core* c2);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

#endif
