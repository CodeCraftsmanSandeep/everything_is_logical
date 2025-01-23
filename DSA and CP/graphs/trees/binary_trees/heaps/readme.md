- Heaps
  - Heaps have following properties:
    - Complete Binary Tree (CBT)
    - Heap order property (min and max heap characteristic, that is relation between parent and child value)
  - min heap is used for ascending order priority queue
  - max heap is used for descending order priority queue

- I generally use binary heaps, so that is the reason heaps is kept inside binary_trees repository.
- Priority queues is written here, becuase most of the time priority queses are implement using binary heaps.
  - operations
    - insert(x)
    - remove() high priority element
    - get() high priority element
  - priorirty queues can be implemented using
    - arrays O(n)
    - linkedlist O(n)
    - heaps O(logn)
    - BST O(logn)
- Heap vs PQ
  - Heap is a specific data structure with the heap property and is commonly used to implement Priority Queues.
  - Priority Queue is an abstract concept for a queue where each element has a priority, and the element with the highest or lowest priority is served first. A heap is one of the most efficient ways to implement a priority queue. 
- Height of heap (complete binary tree) is : floor(log2(n)) where n is the number of elements in heap.

| title | notes |
|:------|:------|
| [min_heap.hpp](min_heap.hpp), [min_heap_test.cpp](min_heap_test.cpp) | generic, dynamic min heap |
| [make_heap_and_heap_sort.cpp](make_heap_and_heap_sort.cpp) | Time complexity is O(n), space O(1), see proof: [proof_page1.jpg](proof_page1.jpg), [proof_page2.jpg](proof_page2.jpg) |
| [make_heap_and_heap_sort.cpp](make_heap_and_heap_sort.cpp) | heap sort, time: O(nlogn), space: O(1) |
| [Find k largest elements](https://www.geeksforgeeks.org/problems/k-largest-elements4206/1) | Standard question which is solved using heaps. My code: [find_k_largest_elements.cpp](find_k_largest_elements.cpp) |
| [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/) | [median.cpp](median.cpp), nice code |

 




