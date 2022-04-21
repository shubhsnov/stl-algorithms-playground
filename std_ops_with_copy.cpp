#include <algorithm>
#include <iostream>
#include <vector>

#include <thread>
#include <chrono>
#include <iomanip>
#include <random>
void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
int gen() {
    std::mt19937 mt{std::random_device{}()};
    return mt()%100;
}
// Template to print vector using cout (NOTE)
template<class Os, class Co> Os& operator<<(Os& os, const Co& v) {
  for (auto i : v) os << i << ' ';
  return os << '\t';
}
// These are operations which do the same thing as the normal std ops but in another container.
int main(int argc, char ** argv) {
    std::string str = "before remove_copy: ";
    std::cout << std::quoted(str) << '\n'; // (NOTE)
    std::vector<int> nums = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    std::cout << nums << '\n';
    std::vector<int> copy_nums;
    std::vector<int> copy_nums2(6);
    // (NOTE) std::begin(copy_nums) will not work (segmentation fault) since copy_nums doesn't have
    // any elements so we have to instruct it to use push_back operation only 
    auto it = std::remove_copy(std::begin(nums), std::end(nums), std::back_inserter(copy_nums), 99);
    std::string str2 = "after remove_copy: ";
    std::cout << std::quoted(str2) << '\n';
    std::cout << copy_nums << '\n';
    // std::begin(copy_nums) works here as the container is at least 6 elements wide (which is the need here).
    auto it2 = std::remove_copy(std::begin(nums), std::end(nums), std::begin(copy_nums2), 99);
    std::string str3 = "after remove_copy2: ";
    std::cout << std::quoted(str3) << '\n';
    std::cout << copy_nums2 << '\n';
    // In case it had more than 6 elements we'd need to use erase as in simple "std::remove"

    //Same rules apply as above
    std::vector<int> nums2 = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    std::vector<int> nums_copy2;
    std::unique_copy(std::begin(nums2), std::end(nums2), std::back_inserter(nums_copy2));
    std::cout << nums_copy2 << '\n';

    std::vector<int> nums_copy_2;
    std::reverse_copy(nums.begin(), nums.end(), std::back_inserter(nums_copy_2));
    printVector(nums_copy_2);

    std::vector<int> nums_copy3;
    std::rotate_copy(nums.begin(), nums.begin() + 5, nums.end(), std::back_inserter(nums_copy3));
    printVector(nums_copy3);

    std::vector<int> nums_copy4;
    std::replace_copy(std::begin(nums), std::end(nums), std::back_inserter(nums_copy4), 99, 43);
    std::cout << nums_copy4 << '\n';

    // Creates two collections based on predicate
    std::vector<int> true_arr;
    std::vector<int> false_arr;
    auto retval = std::partition_copy(nums.begin(), nums.end(), std::back_inserter(true_arr), std::back_inserter(false_arr), [] (const int &a) {
        return a % 2 == 0; // will partition based on odd even
    });
    //std::cout << *(retval.first) << *(retval.second) << std::endl;
    printVector(true_arr);
    printVector(false_arr);
    
    //Sorts some of the elements in the range [first, last) in ascending order, storing the result in the range
    // [d_first, d_last).
    //At most d_last - d_first of the elements are placed sorted to the range [d_first, d_first + n). 
    //n is the number of elements to sort (n = min(last - first, d_last - d_first)). The order of equal
    // elements is not guaranteed to be preserved.
    std::vector<int> nums_copy6 {10, 12, 45};
    // (NOTE) Here the size of the copy container (cc) matters if any, meaning if original container (oc) has 5 elements 
    // and copy container has 3 elements the oc will be sorted and first 3 elements will be copied to cc.
    // If cc is larger then first 5 elemenst of cc will overwritten with sorted oc
    std::partial_sort_copy(nums.begin(), nums.end(), std::begin(nums_copy6), std::end(nums_copy6));
    printVector(nums_copy6);
    return 0;
}