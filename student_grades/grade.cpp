#include <vector>
#include <stdexcept>

#include "grade.h"

using namespace std;

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0) {
        throw domain_error("student ha done no homework");
    }

    return grade(midterm, final, median(hw));
}
