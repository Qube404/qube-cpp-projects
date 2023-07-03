#ifndef GUARD_median_h
#define GUARD_median_h

#include <stdexcept>
#include <algorithm>

#include "vec.h"

template <class In>
double median(In begin, In end) {
    if (begin == end) {
        throw std::domain_error("median of an empty collection");
    }

    Vec<double> v;
    while (begin != end) {
        v.push_back(*begin++);
    }

    //sort(v.begin(), v.end());

    typedef typename Vec<double>::size_type vec_sz;
    vec_sz size = v.size();
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

#endif
