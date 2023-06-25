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

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    vector<StudentInfo> fails = extract_fails(students);
    
    sort(students.begin(), students.end(), compare);
    sort(fails.begin(), fails.end(), compare);
    
    cout << "Passed: " << endl;
    output_students(cout, students, maxlen);

    cout << endl;

    cout << "Failed: " << endl;
    output_students(cout, fails, maxlen);

    return 0;
}
