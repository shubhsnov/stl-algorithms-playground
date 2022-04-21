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
// These are operations which do the same thing as the normal std ops but with a predicate.
int main(int argc, char ** argv) {
    std::vector<int> nums = { 5, 2, 1, -2, -4, 4, 6, 12, 12, 5, 98 };

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

    std::vector<int> nums2 = { 5, 2, 4, 6, 12, 5, 98, 12, 12 };
    // count
    int count_of_5 = std::count_if(nums2.begin(), nums2.end(), [] (int& a) {
        return (a == 5);
    });
    std::cout << count_of_5 << std::endl;

    std::vector<int> nums3 = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    auto it = std::remove_if(std::begin(nums3), std::end(nums3), [] (int& a) {
        return (a == 99);
    });
    std::cout << nums3 << '\n';
    nums3.erase(it, std::end(nums3));
    std::cout << nums3 << '\n';

    std::vector<int> nums4 = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    std::vector<int> copy_nums4;
    // (NOTE) std::begin(copy_nums) will not work (segmentation fault) since copy_nums doesn't have
    // any elements so we have to instruct it to use push_back operation only 
    auto it4 = std::remove_copy_if(std::begin(nums4), std::end(nums4), std::back_inserter(copy_nums4), [] (int& a) {
        return (a == 99);
    });
    std::cout << copy_nums4 << '\n';

    std::vector<int> nums5 = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    std::replace_if(std::begin(nums5), std::end(nums5), [] (int& a) {
        return (a % 2 != 0);
    }, 43);
    std::cout << nums5 << '\n';

    std::vector<int> nums6 = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    std::vector<int> nums_copy6;
    std::replace_copy_if(std::begin(nums6), std::end(nums6), std::back_inserter(nums_copy6), [] (int& a) {
        return (a % 2 != 0);
    }, 43);
    std::cout << nums_copy6 << '\n';


    std::vector<int> a = { 1, 2, 3, 4, 4, 5, 6, 7 };

    // (NOTE)
    std::copy_if(std::begin(a), std::end(a),
                 std::ostream_iterator<int>(std::cout, "|"),
                 [](int x) { return x % 2 != 0; });
    std::cout << '\n';
    return 0;
}