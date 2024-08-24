## structs and classes in C++
- Techinical difference
  - there is only one technical difference
    - that is data members and functions in structs are public by default whereas in class they are private by default.
    - that is the only technical difference
  - Wow, what a big difference right!??
- Is there any thing that structs can do that cannot be done by class in C++?
  - NO
- Is there any thing that a class can do that cannot be done by struct in C++?
  - NO! 
- Then why do they exist?? why cant we just have one between struct and class in C++
  - C++ was built on top of C
    -  C++ was built on top of C, and early versions of C++ compilers translated C++ code to C, which was then compiled by local C compilers. This led to the language’s ability to call C libraries and functions, including malloc and free.
    -  However, it does not mean that C++ is 100% **backward compatible** with C. There are differences in language semantics, and non-trivial C programs may not compile as C++ code without modification. The object files produced by C and C++ compilers can also have important differences, which manifest when intermixing C and C++ code.
    -  In C, struct is used solely for grouping data together. A struct in C is a collection of variables (possibly of different types) under a single name. It doesn’t support member functions or other object-oriented features.
    - In C++, struct can do everything a class can do. It supports member functions, constructors, destructors, inheritance, and access specifiers.
    - For historical reasons structs and classes are eisting in C++.
  - Different use cases developed by coders
    - struct is generally used to group some set of data with very simple logic, whereas classes are born for being complex!!

## Shallow copy vs deep copy in C++
- [article](https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/)
- [my code](shallow_vs_deep.cpp)