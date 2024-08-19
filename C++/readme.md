# Strings
| memorize | quick notes | my_stuff |
|:--|:--|:--|
| reverse() | | |
| reverse_copy() | | |
| substr(pos, len)  | pass starting index and length of sub-string | |
| append() | https://cplusplus.com/reference/string/string/append/ | | 
| stoi(), stol(), stoll() | | [string/practise1](string/practise1) |


# bitset

| | | 
|:--|:--|
| to_string(), to_ulong(), to_ullong() | | 

# operators

| operator | notes |
|:---------|:------|
| / | n/m = sign(n)*sign(m)*(floor(abs(n) div abs(m))) |
| % | n%m = sign(n) * (abs(n)%abs(m)) i.e sign of n%m is same as n except the case of abs(n)%abs(m) = 0 and n != 0 |


# vector
- https://www.geeksforgeeks.org/vector-in-cpp-stl/
- Difference between ```emplace_back``` and ```push_back```
  - [stackoverflow](https://stackoverflow.com/questions/26198350/c-stacks-push-vs-emplace/26198609)

# functions
- function prototype
  - A function prototype is a declaration of a function that specifies the function’s name, return type, and parameters. It informs the compiler about the function’s existence and how it should be called, but it does not include the function body. Prototypes are usually placed at the beginning of the code file or in header files.
- function signature
  - The function signature refers to the part of the function prototype or function definition that includes the function’s name and the types of its parameters. The return type is not part of the function signature.
  - C++ does not allow to define functions with same function signature.
    - What does this mean
      - The following code will cause compilation error <br/> 
		```cpp
		int add(int num1, int num2){
			return num1 + num2;
		}

		string add(int num1, int num2){
			return to_string(num1) + to_string(num2);
		}
		```
	  - But the below code will not cause any compilation errors <br/>
		```cpp
		int add(int num1, int num2){
			return num1 + num2;
		}

		string add(long long int num1, int num2){
			return to_string(num1) + to_string(num2);
		}
		```
- function definition
  - which contains the logic as well as it can define the function as well.

# OOPS
- Abstraction
- Encapsulation
- Data hiding
- Inheritence
	- Single inheritence
	- Multilevel inheritence (Destructors are always called in reverse order of constructors) ([related_question](https://www.geeksforgeeks.org/questions/c-inheritance-question-4/))	
	- Multiple inheritence
	- Hierarchial inheritence
	- Hybrid inheritence
- Reusability
- Polymorphism
  - ability to take many forms
  - types
    - compile time polymorphism
      - function overloading
        - functions can be overloaded, if the signatures are not the same
        - do not forget to note the const keyword in function overloading. see this [article](https://www.geeksforgeeks.org/function-overloading-and-const-functions/)
      - operator overloading
    - run time polymorphism (Late binding and dynamic polymorphism are other names for runtime polymorphism)
      - function overriding
      - virtual functions

### notes
- getters and setters
- friend classes and functions in c++
- diamond problem (src: [link](https://www.geeksforgeeks.org/multiple-inheritance-in-c/), [related_question](https://www.geeksforgeeks.org/questions/c-inheritance-question-12/))
	- solution: use ```virtual keyword```
- The base class members cannot be directly assigned using initializer list in derived class member function. (src: [question_link](https://www.geeksforgeeks.org/questions/c-inheritance-question-11/))
- A Base class pointer/reference can point/refer to a derived class object, but the other way is not possible. (src: [related_question](https://www.geeksforgeeks.org/questions/c-inheritance-question-6/))
- virtual functions
  - virtual functions are resolved late, at runtime.
  - pure virtual functions
    - [some more code](pure_virtual.cpp)
  - vtable and vptr are used to get corresponding function definition at run-time.
  - virtual destructors ([article](https://www.geeksforgeeks.org/virtual-destructor/))
- Interfaces/pure abstract classes in C++
- Object slicing [article](https://www.geeksforgeeks.org/object-slicing-in-c/)
	- object slicing is not possible when base class has at least one **pure virtual method**

# structures in c++

# union in c++

# namepsace 
- helps in avoiding name collisions.
- gives good logical view.
- can be nested.

# exception handling in c++

# Generic programming
- https://www.geeksforgeeks.org/generics-in-c/
- templates in c++
- template spcialization
- template argument deduction
- template metaprogramming (computation at compile time)

# General notes 
- [nullptr vs NULL](nullptr_vs_NULL.md)
- [segmentation fault in c++](https://www.geeksforgeeks.org/segmentation-fault-c-cpp/)
- The default visibility in struct is public, whereas in class is private
- shallow copy vs deep copy
- C++ arrays does not perform bound checking (but why??, this can cause memory leak)
  - see this code: [mem_leak.cpp](mem_leak.cpp)