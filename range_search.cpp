#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

auto print_sequence = [](auto const id, auto const& seq, int pos = -1) {
    std::cout << id << "{ ";
    for (int i{}; auto const& e : seq) {
        const bool mark {i == pos};
        std::cout << (i++ ? ", " : "");
        std::cout << (mark ? ">> " : "") << e << (mark ? " <<" : "");
    }
    std::cout << " }\n";
};
 

int main(int argc, char ** argv) {
    // Not sorted case
    std::vector<int> nums = { 5, 2, 1, -2, -4, 4, 6, 12, 12, 5, 4, 6, 12, 98 };
    std::vector<int> range = { 4, 6, 12 };

    auto result = std::search(std::begin(nums), std::end(nums), std::begin(range), std::end(range));
    if (result != std::end(nums)) {
        std::cout << "Found 4, 6, 12 at :" << std::distance(nums.begin(), result) << std::endl;
    }

    auto result2 = std::find_end(std::begin(nums), std::end(nums), std::begin(range), std::end(range));
    if (result2 != std::end(nums)) {
        std::cout << "Found 4, 6, 12 at :" << std::distance(nums.begin(), result2) << std::endl;
    }

    const std::vector<int> v{0, 2, 3, 25, 5};
    const auto t1 = {19, 10, 3, 4};
    const auto t2 = {1, 6, 7, 9};
 
    auto find_any_of = [](const auto& v, const auto& t) {
        const auto result = std::find_first_of(v.begin(), v.end(),
                                               t.begin(), t.end());
        if (result == v.end()) {
            std::cout << "No elements of v are equal to any element of ";
            print_sequence("t = ", t);
            print_sequence("v = ", v);
        } else {
            const auto pos = std::distance(v.begin(), result);
            std::cout << "Found a match (" << *result << ") at position " << pos;
            print_sequence(", where t = ", t);
            print_sequence("v = ", v, pos);
        }
    };
 
    find_any_of(v, t1);
    find_any_of(v, t2);

    // Relative values
     std::vector<int> v1{3, 1, 4, 1, 5, 9};
 
    std::vector<int>::iterator result3 = std::min_element(v1.begin(), v1.end());
    std::vector<int>::iterator result4 = std::max_element(v1.begin(), v1.end());
    auto result5 = std::minmax_element(v1.begin(), v1.end());
    std::cout << "min element at: " << std::distance(v1.begin(), result3) << std::endl;
    std::cout << "max element at: " << std::distance(v1.begin(), result4) << std::endl;
    if (result3 == result5.first && result4 == result5.second) {
        std::cout << "minmax found correctly\n";
    }
    
    return 0;
}