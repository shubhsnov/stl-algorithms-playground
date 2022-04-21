#include <algorithm>
#include <iostream>
#include <vector>

#include <thread>
#include <chrono>
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

void f1(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "thread " << n << " ended" << std::endl;
}
 

int main(int argc, char ** argv) {
    // Sorted vector also considered a set
    std::vector<int> a = { 1, 2, 3, 4, 4, 5, 6, 7 };
    std::vector<int> b = { 2, 4, 7, 8 };
    std::vector<int> z = { 2, 4 };
    std::vector<int> c, d, e, f;

    std::copy(std::begin(a), std::end(a), std::back_inserter(c));
    printVector(c);

    //copy directly to cout (NOTE)
    std::copy(std::begin(a), std::end(a),
              std::ostream_iterator<int>(std::cout, "-|-"));
    std::cout << '\n';

    // (NOTE)
    std::copy_if(std::begin(a), std::end(a),
                 std::ostream_iterator<int>(std::cout, "|"),
                 [](int x) { return x % 2 != 0; });
    std::cout << '\n';
    
    // std move called on each element
    std::move(std::begin(a), std::end(a), std::back_inserter(d));
    printVector(d);
    printVector(a);
    std::cout << "Length of a: " << a.size() << std::endl;

    // (NOTE)
    std::vector<std::thread> v1;
    std::thread t1(f1, 1);
    std::thread t2(f1, 2);
    std::thread t3(f1, 3);
    v1.emplace_back(std::move(t1)); // Calls the constructor in place
    v1.emplace_back(std::move(t2));
    v1.emplace_back(std::move(t3));
    std::vector<std::thread> l;
 
    // copy() would not compile, because std::thread is noncopyable (NOTE)
    std::move(v1.begin(), v1.end(), std::back_inserter(l)); 
    for (auto& t : l) t.join();

    std::vector<char> v2 = {'a', 'b', 'c', 'd', 'e'};
    std::vector<char> l2 = {'1', '2', '3', '4', '5'};

 
    std::swap_ranges(v2.begin(), v2.begin()+3, l2.begin());
 
    std::cout << v2 << '\n' << l2 << std::endl;


    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 8, 9, 10};

    std::copy_backward(vec1.begin(), vec1.begin() + 5, vec1.begin() + 8);
    std::cout << vec1 << *(vec1.end() - 1) << "\n"; // End is last + 1 (NOTE)   

    std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 8, 9, 10};

    std::move_backward(vec2.begin(), vec2.begin() + 5, vec2.begin() + 8);
    std::cout << vec2 << *(vec2.end() - 1) << "\n"; // End is last + 1 (NOTE)  
    return 0;
}