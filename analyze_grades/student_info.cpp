#include <algorithm>

#include "student_info.h"

using std::istream; using std::vector;

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

vector<StudentInfo> extract_fails(vector<StudentInfo>& s) {
    vector<StudentInfo>::iterator iter = stable_partition(s.begin(), s.end(), pgrade);
    vector<StudentInfo> fail(iter, s.end());
    s.erase(iter, s.end());

    return fail;
}

bool did_all_hw(const StudentInfo &s) {
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
