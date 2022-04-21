#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Template to print vector using cout (NOTE)
template<class Os, class Co> Os& operator<<(Os& os, const Co& v) {
  for (auto i : v) os << i << ' ';
  return os << '\t';
}

int main(int argc, char ** argv) {
    // Sorted vector also considered a set
    std::vector<int> a = { 1, 2, 3, 4, 4, 5, 6, 7 };
    std::vector<int> b = { 2, 4, 7, 8 };
    std::vector<int> z = { 2, 4 };
    std::vector<int> c, d, e, f;

    std::set_difference(std::begin(a), std::end(a), std::begin(b), std::end(b), std::back_inserter(c)); // Linear complexity (How?)
    printVector(c);

    std::set_intersection(std::begin(a), std::end(a), std::begin(b), std::end(b), std::back_inserter(d)); // Linear complexity (How?)
    printVector(d);

    std::set_union(std::begin(a), std::end(a), std::begin(b), std::end(b), std::back_inserter(e)); // Linear complexity (How?)
    printVector(e);

    std::set_symmetric_difference(std::begin(a), std::end(a), std::begin(b), std::end(b), std::back_inserter(f)); // Linear complexity (How?)
    printVector(f);

    std::cout
    << a << "\tincludes:\t" << std::boolalpha
    << z << ": " << std::includes(a.begin(), a.end(), z.begin(), z.end()) << '\n';

    std::vector<int> dst;
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(dst)); // has different output to union

    std::cout
    << a << " merged with " << b << "is : " << dst << '\n';
    return 0;
}