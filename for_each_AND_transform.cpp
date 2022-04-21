#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
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

int main(int argc, char ** argv) {
    std::vector<int> nums = { 5, 2, 1, -2, -4 };
    std::vector<std::string> results;

    std::transform(std::begin(nums), std::end(nums), std::back_inserter(results), [] (int &a) {
        return std::to_string(a*10 - a + 123) + ".*--^";
    });
    std::cout << results << "\n";

    std::vector<int> nums_y = { 2, -22, 4, 44, 0 };
    std::vector<std::string> results_2;

    std::transform(std::begin(nums), std::end(nums), std::begin(nums_y), std::back_inserter(results_2), [] (int &a, int&y) {
        return std::to_string(a*10 - y + 123) + "...";
    });
    std::cout << results_2 << "\n";

    // for_each is use for side_effects
    std::for_each(std::begin(nums), std::end(nums), [] (int &a) {
        std::cout << std::to_string(a*10 - a + 123) + "..." << "\n";
    });

    return 0;
}