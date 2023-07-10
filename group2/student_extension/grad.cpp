#include "grad.h"

#include <iostream>
#include <algorithm>

using namespace std;

/*
void Grad::constructor_one() {
    std::cerr << "Grad::Grad()" << std::endl;
}

void Grad::constructor_two() {
    std::cerr << "Grad::Grad(istream&)" << std::endl;
}
*/

istream& Grad::read(istream& in) {
    Core::read_common(in);
    in >> thesis;
    read_hw(in, Core::homework); return in;
}

double Grad::grade() const {
    return min(Core::grade(), thesis);
}


