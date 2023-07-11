#include "ptr.h"
#include "vec.h"

template <>
Vec<char>* clone(const Vec<char>* vp) {
    return new Vec<char>(*vp);    
}

bool compare_Core_ptrs(const Ptr<Core> c1, const Ptr<Core> c2) {
    return c1->name() < c2->name();
}
