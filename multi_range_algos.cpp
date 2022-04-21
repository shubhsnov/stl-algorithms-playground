#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void printArray(int* vec) {
    for (int i = 0; i < 8; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    std::vector<int> nums_e = { 2, 4, 6, 8, 10, 12, 14 };
    std::vector<int> nums_o = { 2, 4, 6, 8, 10, 12, 14 };
    std::vector<int> nums_p = { 2, 6, 4, 8, 12, 10, 14 };

    if (std::equal(nums_e.cbegin(), nums_e.cend(), nums_o.cbegin())) { // Next argument can be a predicate
        std::cout << "All numbers are equal\n";
    }

    if (std::is_permutation(nums_e.cbegin(), nums_e.cend(), nums_p.cbegin())) { // Next argument can be a predicate
        std::cout << "All numbers are same but a different permutations\n";
    }

    std::string_view str1 = "abcdefgh";
    std::string_view str2 = "ABCDEFGH";

    if (std::equal(str1.cbegin(), str1.cend(), str2.cbegin(), [] (const char s1, const char s2) {
        return std::toupper(s1) == std::toupper(s2);
    })) { // Next argument can be a predicate
        std::cout << "The strings are equal on a case insensitive basis\n";
    }

    std::string_view st1 = "abcdef";
    std::string_view st2 = "abcy";

    if (std::lexicographical_compare(st1.cbegin(), st1.cend(), st2.cbegin(), st2.cend())) { // Next argument can be a predicate
        std::cout << "st1 is less than st2\n";
    }

    // Pair of iterators containging not first non-matching elements
    auto mismatch_pair = std::mismatch(st1.cbegin(), st1.cend(), st2.cbegin());
    std::cout << *(mismatch_pair.first) << " is not equal to " << *(mismatch_pair.second) << std::endl;


    return 0;
}