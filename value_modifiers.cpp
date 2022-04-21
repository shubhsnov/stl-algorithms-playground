#include <algorithm>
#include <iostream>
#include <vector>

#include <thread>
#include <chrono>

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

int main(int argc, char ** argv) {
    std::vector<int> nums(10);
    
    std::fill(std::begin(nums), std::end(nums), 42);
    std::cout << nums << '\n';

    std::vector<int> nums2(10);
    
    std::generate(std::begin(nums2), std::end(nums2), gen);
    std::cout << nums2 << '\n';

    std::vector<int> nums3(10);
    
    std::iota(std::begin(nums3), std::end(nums3), 42);
    std::cout << nums3 << '\n';

    
    std::replace(std::begin(nums), std::end(nums), 42, 43);
    std::cout << nums << '\n';
    return 0;
}