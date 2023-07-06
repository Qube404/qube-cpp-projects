#ifndef GUARD_vec
#define GUARD_vec

#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <iostream>

template <class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec(): data(0), avail(0), limit(0) { }
    explicit Vec(size_t n, const T& val = T()) { create(n, val); }
    ~Vec() { uncreate(); }

    Vec(const Vec& v) { create(v.begin(), v.end()); }

    size_type size() const { return limit - data; }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    Vec& operator=(const Vec&);

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    void push_back(const T& val) {
        if (avail == limit) {
            grow();
        }

        unchecked_append(val);
    }

    iterator insert(size_type pos, iterator i, iterator j);

    iterator erase(iterator);
    iterator erase(iterator, iterator);

    void clear();
    bool empty() const;

    void assign(iterator, size_type);

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc;

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);
}; 

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
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    if (&rhs != this) {
        uncreate();

        create(rhs.begin(), rhs.end());
    }

    return *this;
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::grow() {
    size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
typename Vec<T>::iterator Vec<T>::insert(size_type index, iterator i, iterator j) {
    iterator pos = data + index;
    if (j < i) {
        return data + index;
    }

    size_type iter_size = j - i; 
    size_type init_size = size();
    while ((init_size + iter_size) > size()) {
        grow();
    }

    // Grow may change where data is located so need
    // to re evaluate the position.
    pos = data + index;
    std::uninitialized_copy(pos, avail, pos + iter_size);
    std::uninitialized_copy(i, j, pos);
    
    avail += iter_size;

    return pos;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator i) {
    if (i > avail || i < data) {
        throw std::out_of_range("Beyond vector elements");
    }

    alloc.destroy(i);
    iterator it = std::uninitialized_copy(i + 1, avail, i);
    alloc.destroy(it);
    --avail;

    return avail;
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator beg, iterator end) {
    iterator stop = end - 1;
    if (beg > avail || stop < data || stop > avail || stop < data || stop < beg) {
        return end;
    }

    iterator iter = beg;
    while (iter != stop) {
        alloc.destroy(iter);
        ++iter;
    }

    avail = std::uninitialized_copy(end, avail, beg);

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

template <class T>
void Vec<T>::assign(iterator arr, size_type count) {
    clear();
    create(arr, arr + count);    
}

#endif
