#include <vector>
#include <string>

struct PermutedIndex {
    std::string line1;
    std::string line2;
};

std::string str_to_lower(std::string&);

std::vector<PermutedIndex> rotate_string(const std::string&);
std::vector<PermutedIndex> rotate_string(const std::vector<std::string>&);

bool compare_permuted_indexes(const PermutedIndex&, const PermutedIndex&);


typedef std::vector<std::string>::size_type str_vec_sz;
typedef std::vector<PermutedIndex>::size_type perm_vec_sz;
typedef std::string::size_type str_sz;
