#include "grad.h"

#include <iostream>
#include <algorithm>

using namespace std;

istream& Grad::read(istream& in) {
    Core::read_common(in);
    in >> thesis;
    read_hw(in, Core::homework); 
    return in;
}

double Grad::grade() const {
    cerr << "Grad::grade()" << endl;
    return min(Core::grade(), thesis);
}


