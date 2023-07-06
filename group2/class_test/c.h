#include <iostream>

template <class T>
class myclass {
public:
    myclass() { std::cout << "cret" << std::endl; };
    ~myclass() { std::cout << "dest" << std::endl; };

    void something();
};
