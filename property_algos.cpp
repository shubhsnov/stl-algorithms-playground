#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void printArray(int* vec) {
    for (int i = 0; i < 8; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    std::vector<int> nums_e = { 2, 4, 6, 8, 10, 12, 14 };

    if (std::all_of(nums_e.cbegin(), nums_e.cend(), [](int i){ return i % 2 == 0; })) {
        std::cout << "All numbers are even\n";
    }

    if (std::none_of(nums_e.cbegin(), nums_e.cend(), std::bind(std::modulus<>(), std::placeholders::_1, 2))) {
        std::cout << "None of them are odd\n";
    }

    struct DivisibleBy
    {
        const int d;
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };
 
    if (std::any_of(nums_e.cbegin(), nums_e.cend(), DivisibleBy(7))) {
        std::cout << "At least one number is divisible by 7\n";
    }

    // For empty collection -> all_of - true, any_of - false, none_of - true

    return 0;
}