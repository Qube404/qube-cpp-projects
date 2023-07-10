#ifndef GUARD_core
#define GUARD_core

#include <iostream>
#include <string>
#include <vector>

class Core {
friend class StudentInfo;

public:
    Core(): midterm(0), final(0) {
        //constructor_one();
    }

    Core(std::istream& is) { 
        read(is); 
        //constructor_two();
    }

    //virtual void constructor_one();
    //virtual void constructor_two();

    virtual ~Core() {}

    std::string name() const;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;

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