#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
    cout << "Please enter any amount of numbers: ";

    vector<double> homework;
    double x;

    while(cin >> x) {
        homework.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if(size <= 3) {
        cout << endl << "You must enter at least 3 numbers." << endl;
        return 1;
    }

    sort(homework.begin(), homework.end());

    vec_sz mid = size / 2;
    double quartiles[3];

    if (size % 2 == 0) {
        quartiles[0] = (homework[mid/2] + homework[mid/2-1]) / 2;
        quartiles[1] = (homework[mid] + homework[mid-1]) / 2;
        quartiles[2] = (homework[mid/2*3] + homework[mid/2*3]) / 2;
    }  else {
        quartiles[0] = homework[mid/2];
        quartiles[1] = homework[mid];
        quartiles[2] = homework[mid/2*3];
    }

    streamsize prec = cout.precision();
    cout << "Quartiles: " << setprecision(3) 
         << quartiles[0] << " " << quartiles[1] << " " << quartiles[2] 
         << setprecision(prec) << endl;

    return 0;
}
