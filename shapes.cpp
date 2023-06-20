#include <iostream>
#include <string>

using std::cout;
using std::endl;

using std::string;

int main() {
    int height = 7;
    int width = height * 2;

    // Square
    for (int i = 0; i != height; i++) {

        int j = 0;
        while (j != height * 2) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << "*";
                ++j;
            } else {
                cout << string(width - 2, ' ');
                j += width - 2;
            }
        }

        cout << endl;
    }

    cout << endl;
    width = height * 4;

    // Rectangle
    for (int i = 0; i != height; i++) {

        int j = 0;
        while (j != width) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << "*";
                ++j;
            } else {
                cout << string(width - 2, ' ');
                j += width - 2;
            }
        }

        cout << endl;
    }

    cout << endl;
    int odd = 1;
    height = 7;
    width = height * 2 - odd;

    // Triangle
    for (int i = 0; i != height; i++) {
        if (i == 0) {
            cout << string(width / 2 - !odd, ' ') << string(!odd + 1, '*');
        } else if (i == height - 1) {
            cout << string(width, '*');
        } else {
            cout << string(height - i - 1, ' ') << "*" << string(i * 2 - odd, ' ') << "*";
        }

        cout << endl;
    }
    
    cout << endl;
}
