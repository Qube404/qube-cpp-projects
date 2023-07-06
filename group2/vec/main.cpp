#include <memory>
#include <iostream>

#include "vec.hpp"

using namespace std;

template <class T>
void println(Vec<T> v) {

    typename Vec<T>::const_iterator iter = v.begin();
    while (iter != v.end()) {
        cout << *iter << endl;
        iter++;
    }
}

int main() {
    // Default init
    Vec<double> v1;    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);

    Vec<double> v2(3, 9);
    v1.insert(, v2.begin(), v2.end());
    println(v1);
}
