#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int num1 = 0;
    int num2 = 0;

    cout << "Enter number 1: ";
    cin >> num1;

    cout << "Now enter number 2: ";
    cin >> num2;

    int larger = 0;
    if (num1 > num2) {
        num2 = num1;
    }
    cout << "Larger number is: " << num2 << endl;;
}
