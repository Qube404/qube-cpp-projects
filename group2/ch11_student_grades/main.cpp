#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "student_info.h"

using namespace std;

int main() {
    vector<StudentInfo> students;
    StudentInfo record;
    string::size_type maxlen = 0;

    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name()
        << string(maxlen + 1 - students[i].name().size(), ' ');

        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
            << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }

    vector<StudentInfo>::const_iterator it = students.begin();
    while (it != students.end()) {
        cout << it->cret << " " << it->asi << " " << it->cop << " " << it->dest << endl;
        it++;
    }

    return 0;
}
