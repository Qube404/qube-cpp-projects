#ifndef GUARD_str
#define GUARD_str

#include <cstring>
#include <string>

#include "vec.h"

class Str {
    friend std::istream& operator>>(std::istream& is, Str& s);

public:
    typedef Vec<char>::size_type size_type;
    typedef Vec<char>::iterator iterator;
    typedef Vec<char>::const_iterator const_iterator;

    Str() { }

    Str(size_type n, char c): data(n, c) { }

    Str(const char* cp) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }

    template <class In> 
    Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));

        return *this;
    }

    Str& operator+=(Str& s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));

        return *this;
    }
    
    Str& operator+=(const char* s) {
        std::copy(s, s + strlen(s) - 1, std::back_inserter(data));

        return *this;
    }

    Str& operator+=(char* s) {
        std::copy(s, s + strlen(s) - 1, std::back_inserter(data));

        return *this;
    }

    Str& operator+=(const char s) {
        this->data.push_back(s);

        return *this;
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    operator bool() const {
        return data.size() > 0;
    }

    size_type size() const { return data.size(); }

    char* c_str() const {
        char *str_to_char = new char[data.size()];
        
        for (size_type i = 0; i != data.size(); i++) {
            str_to_char[i] = data[i];
        }
        str_to_char[data.size()] = '\0';

        return str_to_char;
    }

    char* c_data() const {
        char *str_to_char = new char[data.size() - 1];

        for (size_type i = 0; i != strlen(str_to_char); i++) {
            str_to_char[i] = data[i];
        }

        return str_to_char;
    }

    size_type copy(char *p, size_type n) {
        for (size_type i = 0; i != n; i++) {
            *p = data[i];

            p++;
        }
        
        return n;
    }

    iterator begin() {
        return data.begin();
    }

    const_iterator begin() const {
        return data.begin();
    }

    iterator end() {
        return data.end();
    }

    const_iterator end() const {
        return data.end();
    }

private:
    Vec<char> data;
};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

std::istream& getline(std::istream&, Str&);

Str operator+(const Str& s, const Str& t);
Str operator+(const Str& s, const char* t);

bool operator>(const Str& lhs, const Str& rhs);
bool operator>=(const Str& lhs, const Str& rhs);
bool operator<(const Str& lhs, const Str& rhs);
bool operator<=(const Str& lhs, const Str& rhs);
bool operator==(const Str& lhs, const Str& rhs);
bool operator!=(const Str& lhs, const Str& rhs);

#endif
