#include <vector>
#include <string>

struct PermutedIndex {
    std::string line;
    std::string::size_type start;
};

std::vector<PermutedIndex> rotate_string(const std::string&);
