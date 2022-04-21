#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> & vec) {
    for (auto val: vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // partition can be thought of as the partition in quicksort but here it is more generic
    // as it take a custom predicate function (which returns true or false based on a criteria)

    auto retval = std::partition(nums.begin(), nums.end(), [] (const int &a) {
        return a % 2 == 0; // will partition based on odd even
    });
    std::cout << *retval << std::endl;
    printVector(nums);

    std::vector<int> nums1 = { 1, 4, 3, 2, 5, 6, 7, 8 };

    // Same as partition but order is preserved
    retval = std::stable_partition(nums1.begin(), nums1.end(), [] (const int &a) {
        return a % 2 == 0; // will partition based on odd even
    });
    std::cout << *retval << std::endl;
    printVector(nums1);

    // in case of quick sort
    std::vector<int> nums2 = { 10, 2, 13, -4, -5, 6, 17 };
    int pivot = nums2[nums2.size() - 2];
    std::cout << pivot << std::endl;
    retval = std::partition(nums2.begin(), nums2.end(), [pivot] (const int &a) {
        return a < pivot; // will partition by putting pivot in its right place with all smaller elements on left and bigger on the right
    });

    auto point = std::partition_point(nums2.begin(), nums2.end(), [pivot] (const int &a) {
        return a < pivot; // will partition by putting pivot in its right place with all smaller elements on left and bigger on the right
    });
    std::cout << *retval << " " << *point << std::endl;

    // it seems partition and partition_point both return the same value, but partition point is more explicit
    // now we can swap pivot with partion_point and keep partitioning the two halves to achieve quicksort
    printVector(nums2);

    std::cout << "Is partitioned: " << std::is_partitioned(std::begin(nums2), std::end(nums2), [pivot] (const int &a) {
        return a < pivot; // will partition by putting pivot in its right place with all smaller elements on left and bigger on the right
    }) << std::endl;

    // is_partitioned_until available with boost not std
    //
    // nums2.push_back(2);
    // printVector(nums2);
    // auto nums_end = std::is_partitioned_until(std::begin(nums2), std::end(nums2), [pivot] (const int &a) {
    //     return a < pivot; // will partition by putting pivot in its right place with all smaller elements on left and bigger on the right
    // }); // returns iterator
    // std::cout << "Is partitioned until: " << *nums_end << std::endl;

    return 0;
}