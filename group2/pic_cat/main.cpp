#include <vector>
#include <string>
#include <iostream>

#include "picture.h"

using namespace std;

int main() {
    vector<string> vs = {
        "This is a"
        "PICTURE"
    };

    Picture p = vs;
    Picture q = frame(p);
    Picture r = hcat(p, q);
    Picture s = vcat(q, r);
    Picture t = vcat(r, s);
    Picture u = frame(t);

    cout << reframe(frame(u), 'A', '=', '!') << endl;
}
