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
    std::vector<int> nums = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    
    auto it = std::remove(std::begin(nums), std::end(nums), 99);
    std::cout << nums << '\n';

    // since remove doesn't change size, call erase on the container.
    nums.erase(it, std::end(nums));
    std::cout << nums << '\n';

    std::vector<int> nums2 = {1, 2, 99, 99, 99, -1, -2, 99, 0, 1};
    auto it2 = std::unique(std::begin(nums2), std::end(nums2));
    std::cout << nums2 << '\n';

    // since remove doesn't change size, call erase on the container.
    nums2.erase(it2, std::end(nums2));
    std::cout << nums2 << '\n';
    return 0;
}