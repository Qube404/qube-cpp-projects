#include <string>

#include "core.h"
#include "grade.h"

using namespace std;

string Core::name() const { 
    cerr << "Core::name()" << endl;
    return n; 
}

double Core::grade() const {
    cerr << "Core::grade()" << endl;
    return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in) {
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read(istream& in) {
    read_common(in);
    read_hw(in, homework);
    return in;
}

bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}

bool compare_Core_pointers(const Core* c1, const Core* c2) {
    return compare(*c1, *c2);
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();

        double x;
        while (in >> x) {
            hw.push_back(x);
        }

        in.clear();
    }

    return in;
}
