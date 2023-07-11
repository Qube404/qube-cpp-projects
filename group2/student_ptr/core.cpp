#include <string>
#include <map>

#include "core.h"
#include "grade.h"

using namespace std;

string Core::name() const { 
    return n; 
}

double Core::grade() const {
    return ::grade(midterm, final, homework);
}

string Core::letter_grade() const {
    static const map<int, string> letters {
        {97, "A+"},
        {94, "A"},
        {90, "A-"},
        {87, "B+"},
        {84, "B"},
        {80, "B-"},
        {77, "C+"},
        {74, "C"},
        {70, "C-"},
        {60, "D"},
        {20, "E"},
        {0, "F"},
    };

    for (
        map<int, string>::const_iterator it = letters.begin();
        it != letters.end();
        ++it
    ) {
        if (it->first >= grade()) {
            return it->second;
        }
    }

    return "?\?\?";
}

bool Core::valid() const {
    return !homework.empty();
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
