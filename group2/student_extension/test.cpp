#include <iostream>

#include "student_info.h"

using namespace std;

int main() {
    StudentInfo s(cin);
    cout << s.letter_grade() << endl;
}
