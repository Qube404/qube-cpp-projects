#include <stddef.h>
#include <stdexcept>

template <class T>
class RefHandle {
public:
    RefHandle(): refptr(new size_t(1)), p(0) { }
    RefHandle(T* t): refptr(new size_t(1)), p(t) { }
    RefHandle(const RefHandle& h): refptr(h.refptr), p(h.p) {
        ++*refptr;
    }

    RefHandle& operator=(const RefHandle&);
    ~RefHandle();

    operator bool() const { return p; }
    T& operator*() {
        if (p) {
            return *p;
        }

        throw std::runtime_error("unbound RefHandle");
    }

    T* operator->() const {
        if (p) {
            return p;
        }

        throw std::runtime_error("unbound RefHandle");
    }

private:
    T* p;
    size_t* refptr;
};

template <class T>
RefHandle<T>& RefHandle<T>::operator=(const RefHandle& rhs) {
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
RefHandle<T>::~RefHandle() {
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}
