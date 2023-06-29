#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <class B> void reverse(B begin, B end) {
    while (begin != end) {
        --end;

        if (begin != end) {
            B temp = begin;
            *begin = *end;
            *end = *temp;
            //swap(*begin++, *end);
        }
    }
}

int main() {
    vector<string> te = {"e", "i", "o"};
    for (int i = 0; i != te.size(); i++) {
        cout << te[i];
    }
    cout << endl;

    reverse(te.begin(), te.end());
    for (int i = 0; i != te.size(); i++) {
        cout << te[i];
    }
    cout << endl;
}
