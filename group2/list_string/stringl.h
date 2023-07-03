#include <string>
#include <list>

class string_list {
public:
    typedef std::list<std::string> stringl;
    typedef stringl* iterator;
    typedef const stringl* const_iterator;
private:
    std::list<std::string> strings;
};
