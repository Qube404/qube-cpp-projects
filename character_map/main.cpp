#include <sstream>
#include <iostream>

#include "character_map.h"

using namespace std;

int main() {
    string s1("Test1\nTest1\nTest1\nTest1");
    string s2("Test2\nTest2\nTest2\nTest2");

    stringstream ss1(s1);
    stringstream ss2(s2);

    vector<string> sss1;
    vector<string> sss2;

    while (ss1 >> s1) {
        sss1.push_back(s1);
    }
    while (ss2 >> s2) {
        sss2.push_back(s2);
    }

    vector<string> ssss = hcat(sss1, sss2);
    for(vector<string>::const_iterator iter = ssss.begin(); iter != ssss.end(); iter++) {
        cout << *iter << endl;
    }
}
