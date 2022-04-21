#include <algorithm>
#include <iostream>
#include <vector>

#include <string>

void sort_stably();

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
    std::vector<int> nums = { 50, 2, 4, 6, 12, 5, 98 };

    // First three elements sorted
    // Rearranges elements such that the range [first, middle) contains the sorted middle
    // − first smallest elements in the range [first, last).
    std::partial_sort(nums.begin(), nums.begin() + 3,  nums.end());
    printVector(nums);

    // First three elements reverse sorted
    std::vector<int> nums_2 = { 50, 2, 4, 6, 12, 5, 98 };
    std::partial_sort(nums_2.begin(), nums_2.begin() + 3,  nums_2.end(), std::greater<int>());
    printVector(nums_2);

    // All elements sorted
    std::sort(nums.begin(), nums.end());
    printVector(nums);

    std::cout << "Is sorted: " << std::is_sorted(std::begin(nums), std::end(nums)) << std::endl;

    nums.push_back(-2);
    printVector(nums);
    auto nums_end = std::is_sorted_until(std::begin(nums), std::end(nums)); // returns iterator
    std::cout << "Is sorted until: " << *nums_end << std::endl;

    int v[] = { 33, 2, 10, 45, 33, 56, 23, 32 }, i;
    // 33 wo go to its correct position, unsorted left partion with <, unsorted right will be >=
    std::nth_element(v, v + 4, v + 8); // begin, nth_element, end

    printArray(v);

    std::vector<int> nums2 = { 1, 3, 5, 2, 4, 6, 8 };
    // Merge phase of merge sort, combine two sorted lists
    std::inplace_merge(nums2.begin(), nums2.begin() + 3,  nums2.end());
    printVector(nums2);

    sort_stably();
    return 0;
}

struct Employee
{
    int age;
    std::string name;  // Does not participate in comparisons
};
 
bool operator<(const Employee & lhs, const Employee & rhs)
{
    return lhs.age < rhs.age;
}
 
void sort_stably()
{
    std::vector<Employee> v =
    { 
        {108, "Zaphod"},
        {32, "Arthur"},
        {108, "Ford"},
    };  
 
    std::stable_sort(v.begin(), v.end());
 
    for (const Employee & e : v)
        std::cout << e.age << ", " << e.name << '\n';
}