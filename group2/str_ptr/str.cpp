#include "str.h"

#include <iostream>
#include <cstring>
#include <iterator>

using namespace std;

ostream& operator<<(ostream& os, const Str& s) {
    ostream_iterator<char> oter(cout);
    for (Str::size_type i = 0; i != s.size(); i++) {
        *oter = s[i];
    }

    return os;
}

istream& operator>>(istream& is, Str& s) {
    s
        .data
        ->clear();

    char c;
    while (is.get(c) && isspace(c));

    if (is) {
        do {
            s.data->push_back(c);
        } while (is.get(c) && !isspace(c));

        if (is) {
            is.unget();
        }
    }

    return is;
}

istream& getline(istream& is, Str& s) {
    Str t;

    is >> t;
    s += t;
    while (is >> t) {
        s += ' ' + t; 
    }

    return is;
}

Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

Str operator+(const Str& s, const char* t) {
    Str r = s;
    r += t;
    return r;
}

bool operator>(const Str& lhs, const Str& rhs) {
    char *lhc = lhs.c_str();
    char *rhc = rhs.c_str();

    return strcmp(lhc, rhc) > 0;
}

bool operator>=(const Str& lhs, const Str& rhs) {
    char *lhc = lhs.c_str();
    char *rhc = rhs.c_str();

    return strcmp(lhc, rhc) >= 0;
}

bool operator<(const Str& lhs, const Str& rhs) {
    char *lhc = lhs.c_str();
    char *rhc = rhs.c_str();

    return strcmp(lhc, rhc) < 0;
}

bool operator<=(const Str& lhs, const Str& rhs) {
    char *lhc = lhs.c_str();
    char *rhc = rhs.c_str();

    return strcmp(lhc, rhc) <= 0;
}

bool operator==(const Str& lhs, const Str& rhs) {
    char *lhc = lhs.c_str();
    char *rhc = rhs.c_str();

    return strcmp(lhc, rhc) == 0;
}

bool operator!=(const Str& lhs, const Str& rhs) {
    char *lhc = lhs.c_str();
    char *rhc = rhs.c_str();

    return strcmp(lhc, rhc) != 0;
}
