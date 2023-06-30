#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Enter some numbers lulw: " << endl;

    string data = "";
    getline(cin, data);

    double num = 0;
    double num_of_nums = 0;

    stringstream data_stream(data);
    while(data_stream >> data) {
        num += stoi(data);
        ++num_of_nums;
    };

    streamsize prec = cout.precision();
    cout 
        << setprecision(2) << fixed 
        <<"Average Number: " << num / num_of_nums << endl;
}
