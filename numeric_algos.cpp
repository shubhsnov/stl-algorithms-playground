#include <algorithm>
#include <iostream>
#include <vector>

#include <random>
//#include <execution>
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
    std::vector<int> nums = { 5, 2, 4, 6, 12, 5, 98, 12, 12 };

    // count
    int count_of_12 = std::count(nums.begin(), nums.end(), 12);
    std::cout << count_of_12 << std::endl;

    int count_of_5 = std::count_if(nums.begin(), nums.end(), [] (int& a) {
        return (a == 5);
    });
    std::cout << count_of_5 << std::endl;
 
    // accumulate (std::multiplies, next, to_string)
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    int sum = std::accumulate(v.begin(), v.end(), 0);
 
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
 
    auto dash_fold = [](std::string a, int b) {
                         return std::move(a) + '-' + std::to_string(b);
                     };
 
    // std::next(v.begin()) -> v.begin + 1,  std::next(v.begin(), 2) -> v.begin + 2
    std::string s = std::accumulate(std::next(v.begin()), v.end(),
                                    std::to_string(v[0]), // start with first element
                                    dash_fold);
 
    // Right fold using reverse iterators
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
                                     std::to_string(v.back()), // start with last element
                                     dash_fold);
 
    std::cout << "sum: " << sum << '\n'
              << "product: " << product << '\n'
              << "dash-separated string: " << s << '\n'
              << "dash-separated string (right-folded): " << rs << '\n';


    // partial_sum

    std::vector<int> v2 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
    std::vector<int> v3 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
 
    std::cout << "The first 10 even numbers are: ";
    std::partial_sum(v2.begin(), v2.end(), v2.begin());
    printVector(v2);
    // std::partial_sum(v.begin(), v.end(), 
    //                  std::ostream_iterator<int>(std::cout, " "));
    // std::cout << '\n';
 
    std::partial_sum(v3.begin(), v3.end(), v3.begin(), std::multiplies<int>());
    std::cout << "The first 10 powers of 2 are: ";
    printVector(v3);


    // Default implementation - the difference b/w two adjacent items
    std::vector va {4, 6, 9, 13, 18, 19, 19, 15, 10};
    printVector(va);
    std::adjacent_difference(va.begin(), va.end(), va.begin());
    printVector(va);

 
    // Fibonacci
    std::vector<int> a = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // Set difference operation to 1
    adjacent_difference(std::begin(a), std::prev(std::end(a)), std::next(std::begin(a)), std::plus<int>());
    printVector(a);

    std::vector<int> ax{0, 1, 2, 3, 4};
    std::vector<int> bx{5, 4, 2, 3, 1};
 
    int r1 = std::inner_product(ax.begin(), ax.end(), bx.begin(), 0);
    // in comparison to the example below, above is same as
    // std::inner_product(ax.begin(), ax.end(), bx.begin(), 0, std::plus<int>(), std::multiplies<int>());
    std::cout << "Inner product of a and b: " << r1 << '\n';
    // std::plus<int>() same as std::plus<int>{}
    int r2 = std::inner_product(ax.begin(), ax.end(), bx.begin(), 0,
                                std::plus<int>(), std::equal_to<>());
    std::cout << "Number of pairwise matches between a and b: " <<  r2 << '\n'; // answer is 1 + 1 = 2 (2 matches)


    std::string in = "hgfedcba", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out),
                5, std::mt19937{std::random_device{}()});
    std::cout << "five random letters out of " << in << " : " << out << '\n';

    std::vector<int> in1 = {3, 54, 11, 5654, 2, -11}, out1;
    std::sample(in1.begin(), in1.end(), std::back_inserter(out1),
                3, std::mt19937{std::random_device{}()});
    printVector(out1);

    return 0;
}