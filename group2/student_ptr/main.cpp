#include <iomanip>
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "core.h"
#include "grad.h"
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

    sort(students.begin(), students.end(), StudentInfo::compare);

    for (vector<Core>::size_type i = 0; i != students.size(); i++) {
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

    return 0;
}
