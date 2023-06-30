#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {
    cout << "Please enter your first name: ";

    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    string col_pad_input;
    string row_pad_input;

    cout << "Now please enter the padding width: ";
    cin >> col_pad_input;

    cout << "And finally the padding height: ";
    cin >> row_pad_input;

    const int col_pad = std::stoi(col_pad_input);
    const int row_pad = std::stoi(row_pad_input);

    const int rows = row_pad * 2 + 3;
    const string::size_type cols = greeting.size() + col_pad * 2 + 2;

    cout << endl;

    for (int r = 0; r != rows; ++r) {

        string::size_type c = 0;
        while (c != cols) {
            if (r == row_pad + 1 && c == 1) {
                cout << string(col_pad, ' ') << greeting << string(col_pad, ' ');
                c += cols - 2;
            } else if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                cout << "*";
                ++c;
            } else {
                cout << string(cols - 2, ' ');
                c += cols - 2;
            }
        }

        cout << endl;
    }

    return 0;
}
