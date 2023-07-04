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
    println(v1);
    cout << endl;

    v1.erase(v1.begin());
    println(v1);
    cout << endl;

    v1.erase(v1.end() - 2, v1.end());
    println(v1);
    cout << endl;

    // Value init
    Vec<double> v2(4, 1.1);
    println(v2);
    cout << endl;

    Vec<double> v3;

    allocator<Vec<double>> all;
    
    // Destructor test
    all.destroy(&v2);

    v3 = v2;
    cout << v2.size() << endl;
}
