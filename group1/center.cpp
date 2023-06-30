#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> center(const vector<string>& s) {
    vector<string> ret;
    string::size_type maxlen = 0; 

    for (
        vector<string>::const_iterator iter = s.begin();
        iter != s.end();
        ++iter
    ) {
        maxlen = max(maxlen, iter->size());
    }

    for (
        vector<string>::const_iterator iter = s.begin();
        iter != s.end();
        ++iter
    ) {
        string::size_type padding = maxlen - iter->size();
        string::size_type half_pad = padding / 2;
        string::size_type remainder = padding % 2;
        ret.push_back(string(half_pad + remainder, ' ') + *iter + string(half_pad, ' '));
    }

    return ret;
}

int main() {
    string s;
    vector<string> ss;
    while (getline(cin, s)) {
        ss.push_back(s);
    }

    ss = center(ss);
    for (
        vector<string>::const_iterator iter = ss.begin();
        iter != ss.end();
        ++iter
    ) {
        cout << *iter << endl;
    }
}
