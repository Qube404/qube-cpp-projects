#ifndef GUARD_ptr
#define GUARD_ptr

#include <stddef.h>
#include <stdexcept>

#include "vec.h"

template <class T>
class Ptr {
public:
    Ptr(): refptr(new size_t(1)), p(0) { }
    Ptr(T* t): refptr(new size_t(1)), p(t) { }
    Ptr(const Ptr& h): refptr(h.refptr), p(h.p) {
        ++*refptr;
    }

    Ptr& operator=(const Ptr&);
    ~Ptr();

    operator bool() const { return p; }
    T& operator*() const {
        if (p) {
            return *p;
        }

        throw std::runtime_error("unbound Ptr");
    }

    T* operator->() const {
        if (p) {
            return p;
        }

        throw std::runtime_error("unbound Ptr");
    }

    void make_unique() {
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? clone(p) : 0;
        }
    }

private:
    T* p;
    size_t* refptr;
};

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs) {
    ++*rhs.refptr;

    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    refptr = rhs.refptr;
    p = rhs.p;

    return *this;
}

template <class T>
Ptr<T>::~Ptr() {
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

template <class T>
T* clone(const T* tp) {
    return tp->clone();
}

template <>
Vec<char>* clone(const Vec<char>*);

#endif
