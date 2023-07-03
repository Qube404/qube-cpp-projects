#include <cstddef>
#include <memory>

template <class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); }
    explicit Vec(typename T::size_type n, const T& val = T()) { create(n, val); }
    ~Vec() { uncreate(); }

    Vec(const Vec& v) { create(v.begin(), v.end()); }

    size_type size() const { return limit - data; }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    Vec& operator=(const Vec&);

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return limit; }
    const_iterator end() const { return limit; }

    void push_back(const T& val) {
        if (avail == limit) {
            grow();
        }

        unchecked_append(val);
    }

    const_iterator erase(const_iterator);
    const_iterator erase(const_iterator, const_iterator);

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc;

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();
    void uncreate(const_iterator);

    void grow();
    void unchecked_append(const T&);
}; 
