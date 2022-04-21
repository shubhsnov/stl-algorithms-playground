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
    std::vector<int> heap = { 5, 2, 4, 6, 12, 5, 98 };

    // Heapify the entire array
    std::make_heap(heap.begin(), heap.end());

    printVector(heap);
    std::cout << "Is heap: " << std::is_heap(std::begin(heap), std::end(heap)) << std::endl;
    // Add an element at the last 
    heap.push_back(123);
    printVector(heap);
    auto heap_end = std::is_heap_until(std::begin(heap), std::end(heap)); // returns iterator
    std::cout << "Is heap until: " << *heap_end << std::endl;
    // No heapify an almost heap using push_heap
    std::push_heap(heap.begin(), heap.end());

    printVector(heap);
    // Replace the front most (max element) with the last and the heapify the remaining numbers
    std::pop_heap(heap.begin(), heap.end());

    std::cout << heap[heap.size() - 1] << std::endl;

    // To remove from vector 
    heap.pop_back();
    
    // If we don't pop_back the heap, but keep pop_heap-ing the it will sort the array.
    // That is what sort_heap does.
    std::sort_heap(heap.begin(), heap.end());
    
    printVector(heap);

    // Pass custom comparator for min-heap
    //make_heap(Q.begin(), Q.end(), myComp{});
    return 0;
}