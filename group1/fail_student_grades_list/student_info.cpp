#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>

#include "student_info.h"
#include "grade.h"

using namespace std;

bool compare(const StudentInfo& x, const StudentInfo& y) {
    return x.name < y.name;
}

istream& read(istream& is, StudentInfo& s) {
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
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

list<StudentInfo> extract_fails(list<StudentInfo>& s) {
    list<StudentInfo> fail;
    list<StudentInfo>::iterator iter = s.begin();

    while (iter != s.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = s.erase(iter);
        } else {
            ++iter;
        }
    }

    return fail;
}

int output_students(ostream& out, list<StudentInfo>& s, string::size_type maxlen) {
    for (list<StudentInfo>::iterator iter = s.begin();
        iter != s.end(); iter++) {
        out << iter->name
            << string(maxlen + 1 - iter->name.size(), ' ');

        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }

    return 0;
}
