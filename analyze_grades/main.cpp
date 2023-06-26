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
    vector<StudentInfo> did, didnt;
    StudentInfo student;
    string::size_type maxlen = 0;

    while (read(cin, student)) {
        maxlen = max(maxlen, student.name.size());

        if (did_all_hw(student)) {
            did.push_back(student);
        } else {
            didnt.push_back(student);
        }
    }

    if (did.empty()) {
        cout << "No students have done the homework!" << endl;
        return -1;
    }

    if (didnt.empty()) {
        cout << "Every student completed their homework" << endl;
        return -1;
    }
    
    return 0;
}
