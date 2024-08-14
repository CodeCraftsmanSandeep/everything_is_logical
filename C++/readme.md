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
		}```
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

### notes
- getters and setters
- diamond problem (src: [link](https://www.geeksforgeeks.org/multiple-inheritance-in-c/), [related_question](https://www.geeksforgeeks.org/questions/c-inheritance-question-12/))
	- solution: use ```virtual keyword```
- The base class members cannot be directly assigned using initializer list in derived class member function. (src: [question_link](https://www.geeksforgeeks.org/questions/c-inheritance-question-11/))
- A Base class pointer/reference can point/refer to a derived class object, but the other way is not possible. (src: [related_question](https://www.geeksforgeeks.org/questions/c-inheritance-question-6/))
- virtual functions
  - pure virtual functions
- Interfaces/pure abstract classes in C++
- Object slicing [article](https://www.geeksforgeeks.org/object-slicing-in-c/)
	- object slicing is not possible when base class has at least one **pure virtual method**


# General notes 
- [nullptr vs NULL](nullptr_vs_NULL.md)
- [segmentation fault in c++](https://www.geeksforgeeks.org/segmentation-fault-c-cpp/)
- The default visibility in struct is public, whereas in class is private

