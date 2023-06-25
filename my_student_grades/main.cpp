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

    string s;
    stringstream ss;

    while (getline(cin, s)) {
        ss = stringstream(s);

        try {
            read(ss, record);
        } catch (domain_error e) {
            cout << e.what();
            return -1;
        }

        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    sort(students.begin(), students.end(), compare);
    
    cout << endl;
    for (vector<StudentInfo>::size_type i = 0;
         i != students.size(); i++) {
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        streamsize prec = cout.precision();
        cout << setprecision(3) << students[i].final_grade
             << setprecision(prec) << endl;
    }

    return 0;
}
