#include <algorithm>
#include <iostream>
#include <vector>

#include <random>

void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    std::vector<int> nums = { 5, 2, 4, 6, 12, 5, 98 };

    // simple rotation to the left
    // second argument is the number that should be to at the front so rotate till that
    // so it can rotate as much as specified in one go
    std::rotate(nums.begin(), nums.begin() + 1, nums.end());
    printVector(nums);
 
    // simple rotation to the right
    std::rotate(nums.rbegin(), nums.rbegin() + 1, nums.rend());
    printVector(nums);

    // Random number generation
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(nums.begin(), nums.end(), g);
    printVector(nums);

    std::next_permutation(nums.begin(), nums.end());
    printVector(nums);

    std::prev_permutation(nums.begin(), nums.end());
    printVector(nums);

    std::reverse(nums.begin(), nums.end());
    printVector(nums);
    return 0;
}