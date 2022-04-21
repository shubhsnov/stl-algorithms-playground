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
    // fill, copy, move call the assignment operator
    // uninitialized_fill calls ctor on raw memory
    // uninitialized_copy calls copy ctor on raw memory
    // uninitialized_move calls move ctor on raw memory
    // uninitialized_default_construct calls default ctor
    // uninitialized_value_construct calls with value initialization

    // clear the memory using std::destroy
    std::vector<int> v = {1, 2, 4};
    std::destroy(std::begin(v), std::end(v)); // Create raw memory
    std::cout << v << '\n';
    std::uninitialized_fill(std::begin(v), std::end(v), 42);
    std::cout << v << '\n';
    std::destroy(std::begin(v), std::end(v));
    std::cout << v << '\n';

    return 0;
}