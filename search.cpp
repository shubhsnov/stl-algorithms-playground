#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    // Not sorted case
    std::vector<int> nums = { 5, 2, 1, -2, -4, 4, 6, 12, 12, 5, 98 };

    auto result = std::find(std::begin(nums), std::end(nums), 12);
    if (result != std::end(nums)) {
        std::cout << "Found 12" << std::endl;
    }

    auto result1_2 = std::find_if(std::begin(nums), std::end(nums), [](int i){ return i%2 == 0; });
    if (result1_2 != std::end(nums)) {
         std::cout << "Found even at "
                  << std::distance(nums.begin(), result1_2) << ", number is = " << *result1_2 << '\n';
    }

    auto result1_3 = std::find_if_not(std::begin(nums), std::end(nums), [](int i){ return i == 5; });
    if (result1_3 == std::begin(nums)) { // first is returned in true case
         std::cout << "No zeroes found in nums"  << ", number is = " << *result1_3 << '\n';
    } else {
        std::cout << "Found non-5 at "
                  << std::distance(nums.begin(), result1_3) << ", number is = " << *result1_3 << '\n';
    }

    auto result2 = std::adjacent_find(std::begin(nums), std::end(nums));
    if (result2 != std::end(nums)) {
        std::cout << "Found 12, 12" << std::endl;
    }

    auto i2 = std::adjacent_find(nums.begin(), nums.end(), std::less<int>());
    if (i2 == nums.end()) {
        std::cout << "The entire vector is sorted in ascending order\n";
    } else {
        std::cout << "The last element in the non-decreasing subsequence is at "
                  << std::distance(nums.begin(), i2) << ", *i2 = " << *i2 << '\n';
    }

    // Sorted case
    std::vector<int> sorted_nums = { 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 };

    const auto p = std::equal_range(sorted_nums.begin(), sorted_nums.end(), 4);
 
    const auto lower_bound = p.first;
    const auto upper_bound = p.second;
    std::cout << "The range of 4 is from "
                  << std::distance(sorted_nums.begin(), lower_bound) << " to " << std::distance(sorted_nums.begin(), upper_bound) << '\n';

    const auto lb = std::lower_bound(sorted_nums.begin(), sorted_nums.end(), 4);
    const auto ub = std::upper_bound(sorted_nums.begin(), sorted_nums.end(), 4);

    std::cout << "The range of 4 is from "
                  << std::distance(sorted_nums.begin(), lb) << " to " << std::distance(sorted_nums.begin(), ub) << '\n';

    if(std::binary_search(sorted_nums.begin(), sorted_nums.end(), 5)) {
        std::cout << "5 is present" << '\n';
    }
    return 0;
}