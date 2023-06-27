#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    vector<string> vs = {"add", "together"};
    string s = "";

    for_each(vs.begin(), vs.end(), [&](string &n) { s += n + ' '; });
    cout << s << endl;
}
