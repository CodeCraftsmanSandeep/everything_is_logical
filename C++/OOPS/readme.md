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




## links
1) Static data member in class : [GFG article](https://www.geeksforgeeks.org/cpp-static-data-members/)
  - question: Count the number of objects are present 
      ```cpp
      #include <iostream>
      using namespace std;

      class someClass{
      public:
          static int numObjects;

          someClass(){
            numObjects++;
          }
          ~someClass(){
            numObjects--;
          }
      };
      int someClass::numObjects = 0; // initialization

      int main(){
          someClass obj1;
          someClass obj2;

          cout << obj2.numObjects << "\n";
      }
      ```
2) Static keyword in C++ : [GFG article](https://www.geeksforgeeks.org/static-keyword-cpp/)


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
  - [Order of constructors and destructors called during inheritence](https://www.geeksforgeeks.org/order-constructor-destructor-call-c/)

- Reusability

- Polymorphism
  - ability to take many forms
  - types
    1) compile time polymorphism
      i) Function overloading
        - Functions can be overloaded, if the signatures are not the same
        - Do not forget to note the const keyword in function overloading. see this [article](https://www.geeksforgeeks.org/function-overloading-and-const-functions/)
          - C++ allows functions to be overloaded on the basis of the const-ness of parameters only if the const parameter is a reference or a pointer. 
        - Rules to overload a function in C++: [GFG article.](https://www.geeksforgeeks.org/function-overloading-c/)
      ii) Operator overloading
        - [Article.](https://www.geeksforgeeks.org/operator-overloading-cpp/)
        - Operator functions are the same as normal functions. The only differences are, that the name of an operator function is always the operator keyword followed by the symbol of the operator, and operator functions are called when the corresponding operator is used. 
        - All operators cannot be overloaded in C++.
    2) Run time polymorphism (Late binding and dynamic polymorphism are other names for runtime polymorphism)
      - Function overriding can be acheived at compile-time and run-time.
      - [virtual_function_use.cpp](virtual_function_use.cpp)
      - Virtual functions in C++ are used to acheive run-time polymorphism.
      - The function call is resolved at run-time during run-time polymorphism.
      - Runtime Polymorphism cannot be achieved by data members in C++.

### oops notes
- getters and setters
  - These terms are generally used in cases when one wants to define a member function in class to get the value of memeber variable then the function is called getter, similarly a setter can be defined.

- Friend classes and functions in c++
  - Friends can access private memebers in c++. (In real life as well :-))
  - [Article](https://www.geeksforgeeks.org/friend-class-function-cpp/)
  - Friendship is not inherited. [Article](https://www.geeksforgeeks.org/inheritance-and-friendship-in-cpp/)

- diamond problem (src: [link](https://www.geeksforgeeks.org/multiple-inheritance-in-c/), [related_question](https://www.geeksforgeeks.org/questions/c-inheritance-question-12/))
  - solution: use ```virtual keyword```

- The base class members cannot be directly assigned using initializer list in derived class member function. (src: [question_link](https://www.geeksforgeeks.org/questions/c-inheritance-question-11/))
- A Base class pointer/reference can point/refer to a derived class object, but the other way is not possible. (src: [related_question](https://www.geeksforgeeks.org/questions/c-inheritance-question-6/))

- Virtual functions
  - A virtual function (also known as virtual methods) is a member function that is declared within a base class and is re-defined (overridden) by a derived class.
  - Virtual functions are mainly used to acheive **run-time polymorphism**.
  - virtual functions are resolved late, at runtime.
  - Pure virtual function
    - A pure virtual function is declared by assigning 0 in the declaration.
    - [Some code on inheritence and pure virtual functions.](pure_virtual.cpp)
  - vtable and vptr are used to get corresponding function definition at run-time.
    - Working of virtual functions: [GFG article.](https://www.geeksforgeeks.org/virtual-function-cpp/)
  - virtual destructors ([article](https://www.geeksforgeeks.org/virtual-destructor/))

- Interfaces in C++
  - - [Article.](https://www.geeksforgeeks.org/implement-interfaces-using-abstract-class-in-c/)
  - Any class which contains at least one pure virtual function is considered as an abstract class.
    - When a class inherits from an abstract base class in C++, it must override all the pure virtual functions present in the class, or else it becomes abstract itself.
    - An abstract class cannot be used for object instantitaion directly.
    - We can have pointers and references of abstract classes.
  - An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation of that class.
    - The C++ interfaces are implemented using abstract classes and these abstract classes should not be confused with data abstraction which is a concept of keeping implementation details separate from associated data.
  - Classes that can be used to instantiate objects are called concrete classes.

- Object slicing [article](https://www.geeksforgeeks.org/object-slicing-in-c/)
  - object slicing is not possible when base class has at least one **pure virtual method**

- copy constructor, [GFG article](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)
  - default copy constructor does shallow copy, to get deep copy we have to define our own copy constructor
  - it is very important to know, when a copy constructor is called, and when a assignment operator is called.