#include <memory>
#include <stdexcept>

#include "vec.h"

using namespace std;

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    if (&rhs != this) {
        uncreate();

        create(rhs.begin(), rhs.end());
    }
    
    return *this;
}

template <class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate() {
    if (data != 0) {
        iterator it = avail;
        while (it != data) {
            alloc.destroy(--it);
        }
        
        alloc.deallocate(data, limit - data);
    }

    data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow() {
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}

template <class T>
typename Vec<T>::const_iterator Vec<T>::erase(iterator i) {
    if (i > avail || i < data) {
        throw out_of_range("Beyond vector elements");
    }

    alloc.destroy(i);  
    uninitialized_copy(i + 1, avail, i);
    --avail;

    return avail;
}

template <class T>
typename Vec<T>::const_iterator Vec<T>::erase(iterator i, const_iterator j) {
    if (i > avail || i < data) {
        throw out_of_range("Beyond vector elements");
    }

    const_iterator begin = i;

    while (i != j) {
        alloc.destroy(i);

        i++;
    }

    uninitialized_copy(j + 1, avail, begin);
    avail -= j - i;

    return avail;
}

template <class T>
void Vec<T>::clear() {
    iterator it = avail;
    while (it != data) {
        alloc.destroy(--it);
    }
    
    data = limit = avail = 0;
}

template <class T>
bool Vec<T>::empty() const {
    return avail == 0;
}
