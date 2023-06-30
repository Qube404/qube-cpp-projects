#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::streamsize;
using std::setprecision;
using std::domain_error;

int main() {
    cout << "Please enter your first name: ";

    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, followed by end-of-file: ";

    vector<double> homework;
    read_hw(cin, homework);

    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();

        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. Please try again." << endl;
        return -1;
    }

    return 0;
}
