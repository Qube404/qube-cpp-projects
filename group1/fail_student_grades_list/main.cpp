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
    list<StudentInfo> students;
    StudentInfo record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    list<StudentInfo> fails = extract_fails(students);
    
    cout << "Passed: " << endl;
    students.sort(compare);

    cout << endl;

    cout << "Failed: " << endl;
    fails.sort(compare);
    
    output_students(cout, students, maxlen);
    output_students(cout, fails, maxlen);

    return 0;
}
