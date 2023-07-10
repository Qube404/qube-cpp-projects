#include "core.h"
#include "grad.h"

int main() {
    Core* p1 = new Core;
    Grad* p2 = new Grad;
    Core s1;
    Grad s2;

    // Predicted function calls
    p1->grade();
    p1->name();

    p2->grade();
    p2->name();

    s1.grade();
    s1.name();

    s2.grade();
    s2.name();
}
