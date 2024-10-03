# Classes in programming languages
- Declarative programming languages:
  - In computer science, declarative programming is a programming paradigm—a style of building the structure and elements of computer programs—that expresses the logic of a computation without describing its control flow.
  - Many languages that apply this style attempt to minimize or eliminate side effects by describing what the program must accomplish in terms of the problem domain, rather than describing how to accomplish it as a sequence of the programming language primitives (the how being left up to the language's implementation)
  - Examples:
    1) database query languages (e.g., SQL, XQuery)
    2) regular expressions
    3) logic programming (e.g. Prolog, Datalog, answer set programming)
    4) functional programming (Lambda calculus forms the basis of all functional programming languages. )
- Imperative programming
  - In computer science, imperative programming is a programming paradigm of software that uses statements that change a program's state.
  - Imperative programming focuses on describing how a program operates step by step,[1] rather than on high-level descriptions of its expected results.
  - Procedural and Object Oriented Programming langauges are two famous types of imperative programming model.
  - Examples
    1) C
    2) C++
    3) FORTRAN

# libraries
- STL (Standard Template Library): The STL specifically refers to components that use templates to provide generic algorithms and data structures, such as containers (std::vector, std::map), iterators, and algorithms.
- Standard Library: This is a broader term that includes STL components as well as other components such as std::string, input/output facilities (like iostream), and other utilities.


# Enums in C++
- [GFG Article on Enums](https://www.geeksforgeeks.org/enumeration-in-cpp/)
- **Key Considerations:**
  - Be cautious when using enums. Check this example: [enums/enums.cpp](enums/enums.cpp)
  
- **Type Safety:**
  - In C++, enums are strongly typed, meaning you can't implicitly convert between an enum and an `int` without an explicit cast. This provides better type safety than in C.
  
- **How the Compiler Handles Enums:**
  - Enums are stored as integers by default. Internally, an enum variable holds the corresponding integer value of the defined constant.
  -  Like other const expressions, values of enumeration constants are evaluated at compile time. 

- **Restrictions:**
  - C++ enums can only hold integral values (`int`, `char`, `bool`). Non-integral values like floating-point numbers are not allowed.

- **Enum Classes (C++11 and later):**
  - [Why Enum Classes?](https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/)
    - Prevents name conflicts: Two enums can't share the same name, and no variable can have a name that’s already part of an enum.
    - Unlike traditional enums, they are strongly typed and scoped. Enum classes do not allow implicit conversion to `int`, and comparisons between different enums are not permitted.
  - Example code: [enums/enum_classes.cpp](enums/enum_classes.cpp)

- constexpr vs const in C++
  - [Stack overflow](https://stackoverflow.com/questions/13346879/const-vs-constexpr-on-variables)
## pointers and references
- In C++, once a reference is initialized to a variable, it cannot be changed to refer to another variable. A reference must always refer to the variable it was initialized with. This is in contrast to pointers, which can be reassigned to point to different variables.
- Dangling references
  - example: [pointers_and_references/practise1.cpp](pointers_and_references/practise1.cpp)
  - Can be overcommed by:
    - [pointers_and_references/practise2.cpp](pointers_and_references/practise2.cpp)
    - [pointers_and_references/practise3.cpp](pointers_and_references/practise3.cpp)

## Strings
| memorize | quick notes | my_stuff |
|:--|:--|:--|
| reverse() | | |
| reverse_copy() | | |
| substr(pos, len)  | pass starting index and length of sub-string | |
| append() | https://cplusplus.com/reference/string/string/append/ | | 
| stoi(), stol(), stoll() | | [string/practise1](string/practise1) |


## bitset

| | | 
|:--|:--|
| to_string(), to_ulong(), to_ullong() | | 

## operators

| operator | notes |
|:---------|:------|
| / | n/m = sign(n)*sign(m)*(floor(abs(n) div abs(m))) |
| % | n%m = sign(n) * (abs(n)%abs(m)) i.e sign of n%m is same as n except the case of abs(n)%abs(m) = 0|
| ! | Not operator. !(2) = 0 = !(-2), because any non-zero integer is treated as true by ! operator. !(0) = 1 |


## vector
- https://www.geeksforgeeks.org/vector-in-cpp-stl/
- Difference between ```emplace_back``` and ```push_back```
  - [stackoverflow](https://stackoverflow.com/questions/26198350/c-stacks-push-vs-emplace/26198609)

## functions
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
- structs can be defined inside functions, which are called as local structs.
- classes can be defined inside functions, which are called as local classes.
- functions cannot be defined inside functions, but the similar functionality can be obtained by defining lambda functions inside functions.
- 


### lambda functions


## OOPS
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

### oops notes
- getters and setters
- friend classes and functions in c++
  - [Article](https://www.geeksforgeeks.org/friend-class-function-cpp/)
  - Friendship is not inherited. [Article](https://www.geeksforgeeks.org/inheritance-and-friendship-in-cpp/)
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
- templates and static variables
  - [GFG article](https://www.geeksforgeeks.org/templates-and-static-variables-in-c/)
  - Each instance of a template contains its own static variable. 
- template specialization
  - [GFG article](https://www.geeksforgeeks.org/template-specialization-c/)
  - Types of template specialization:
    1) partial specialization
    2) full specialization
- template argument deduction
- template metaprogramming (computation at compile time)
  - decreases run-time execution and memory foot print
    - Memory footprint refers to the amount of main memory that a program uses or references while running.
  - [template_meta_programming.cpp](template_meta_programming.cpp)

# Type inference in C++
- [Rules of inference](https://www.geeksforgeeks.org/rules-of-inference)
- Type inference in C++
  - By using keywords ```cpp auto ```, ```cpp decltype``` 
    - [reference](https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/)

# General notes 
- [nullptr vs NULL](nullptr_vs_NULL.md)
- [segmentation fault in c++](https://www.geeksforgeeks.org/segmentation-fault-c-cpp/)
- C++ arrays does not perform bound checking (but why??, this can cause memory leak)
  - see this code: [mem_leak.cpp](mem_leak.cpp)
- Emplace vs insert in C++ containers
  - [GFG](https://www.geeksforgeeks.org/emplace-vs-insert-c-stl/)
