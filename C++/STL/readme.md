# Containers
- https://www.geeksforgeeks.org/containers-cpp-stl/

## std::initilializer_list
- [article](https://www.geeksforgeeks.org/std-initializer_list-in-cpp-11/)
- Important for implementing STL classes like vector, set etc..
- limitations of initializer_list:
    1) Size cannot be changed: The size of initializer_list is fixed at compile time. It does not have a dynamic nature as a standard container such as a vector. The size of the initializer cannot be changed once it has been created.
    2) Cannot access the elements randomly: initializer_list supports only forward iteration. We cannot access the desired or random element using the index as standard containers.
    3) Immutable elements: The elements within an initializer_list are immutable. Once the list is created, the values cannot be modified. Any attempt to modify the elements through the iterator or by any other means will result in a compilation error.
- member functions:
    - .begin()
    - .end()
    - .size()

## multiset
- [GFG article](https://www.geeksforgeeks.org/multiset-in-cpp-stl/)

## unordered_multiset

## multimap

## unordered_multimap


# algorithm 
- If a = {x1, y1} and b = {x2, y2} are two pairs, then: greater<pair<int, int>>()(a, b) will return true if either x1 > x2, or x1 == x2 and y1 > y2.
