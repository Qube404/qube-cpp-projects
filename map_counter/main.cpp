#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    map<string, int> counters;

    while (cin >> s) {
        ++counters[s];
    }

    vector<string> k;
    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
        k.push_back(it->first);
    }
    sort(k.begin(), k.end());

    for (vector<string>::const_iterator it = k.begin(); it != k.end(); ++it) {
        cout << *it << "\t" << counters[*it] << endl;
    }
}
