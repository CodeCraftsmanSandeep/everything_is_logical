# Difference between C and C++
- C is a procedural programming language and C++ is Object Oriented Programming language
    - For seeing the diference between procedural and object-oriented programming lnaguage, see this artcile : [GFG article](https://www.geeksforgeeks.org/differences-between-procedural-and-object-oriented-programming/)

## 1) C does not support function overloading, C++ supports function overloading
- The below code gives compilation error in C:
    - ```c
        #include <stdio.h>

        void print(int x){
            printf("%d\n", x);
        }

        void print(double x){
            printf("%f\n", x);
        }

        int main(){
            print(2);
            print(2.3);
        }
    ```
- The below code compiles successfully in C++:
    - ```cpp
        // we can also use #include <stdio.h>
        // but its better to you cstdio, to get a clear identification that it is C library
        #include <cstdio> 

        void print(int x){
            printf("%d\n", x);
        }

        void print(double x){
            printf("%f\n", x);
        }

        int main(){
            print(2);
            print(2.3);
        }
        ```
    - output:
        - ```txt
            2
            2.300000
        ```

## 2) C++ support OOP, C does not support OOP

## 3) namespaces are introduced in C++ to avoid name conflicts, C does not support namespace

## 4) inline functions are supported in C++, but not in C
- To know about inline functions in C++: [GFG artcile](https://www.geeksforgeeks.org/inline-functions-cpp/)

## 5) No built in execption handling in C, but C++ has built-in exception handling mechanisms

## 6) default arguments for function in C++ are suppored, but not in C

- The below C++ code has no error:
    - ```cpp
        #include <iostream>

        void print(int x = 2){
            std::cout << x << "\n";
        }

        int main(){
            print();        // output: 2
            print(100);     // output: 100
        }
    ```

# Back ward compatability of C++ with C
- C++ is largely backward-compatible with C, meaning that most valid C code can be compiled and executed as C++ code. However, there are some exceptions where C++ is not fully compatible with C due to differences in language design, type rules, and stricter enforcement of syntax and semantics.
    - So we are basically now going to look at examples where the code is valid in C but not in C++
## Earlier versions of C support implicit int declaration, but C++ does not support this case.
- Note that only C before C99 supported this case:
    - ```c
        #include <stdio.h>

        identity(int x){
            return x;
        }

        int main(){
            printf("Sandeep");
        }
    ```
    - The above code is valid in C <= C99


## Ofcourse the new keywords in C++ can be used in C

- The below code is valid in C but not in C++
    - ```c
        #include <stdio.h>

        int main(){
            int class = 100;
            int namespace = 20;
        }
    ```

## auto keyword in C and C++
The **`auto` keyword** is used in both **C** and **C++**, but it has different meanings and uses in each language. Here's a breakdown of the use of `auto` in **C** and **C++**:

### 1. **`auto` in C** (Pre-C99)
In **C**, the `auto` keyword was historically used to indicate that a variable had **automatic storage duration**. However, in modern C (since **C99**), this usage is largely redundant, as **local variables** are by default considered to have automatic storage duration. 

#### Example (C before C99):
```c
auto int x = 10;  // 'auto' specifies automatic storage duration (default for local variables)
```
- In modern C, you **do not need** to specify `auto` for local variables because they are already automatic by default.

#### Key Points in C:
- **Redundant in C99 and later**: `auto` does not affect the behavior of local variables in C, as all local variables are automatically allocated on the stack by default.
- **No role in C**: The `auto` keyword in C is mostly obsolete and **not used** for type inference, which is its primary function in C++.

---

### 2. **`auto` in C++**
In **C++**, the `auto` keyword is a powerful feature introduced in **C++11**. It allows the compiler to **deduce** the type of a variable based on the type of the expression assigned to it. This is especially useful for reducing code verbosity and for working with iterators or complex types without needing to specify the type explicitly.

#### Key Uses of `auto` in C++:

1. **Type Inference**:
   - The **type** of the variable is automatically deduced by the compiler.
   - It makes code more concise, especially when the type is long or complex.

   **Example** (C++):
   ```cpp
   auto x = 10;   // x is deduced to be of type 'int'
   auto y = 3.14; // y is deduced to be of type 'double'
   ```
- THe below code has no pproblem in C, but cannot be compiled in modern C++ compilers:
    - ```c
        #include <stdio.h>

        int main(){
            auto int x = 200;
        }
        ```

2. **Working with Containers and Iterators**:
   - It is especially useful when working with STL containers and iterators, where the type can be long and complex.

   **Example** (Using `auto` with iterators in C++):
   ```cpp
   #include <vector>
   #include <iostream>
   
   int main() {
       std::vector<int> vec = {1, 2, 3, 4, 5};
       for (auto it = vec.begin(); it != vec.end(); ++it) {
           std::cout << *it << " ";
       }
       return 0;
   }
   // Output: 1 2 3 4 5
   ```

3. **Simplifying Complex Types**:
   - `auto` is also useful for simplifying the syntax when dealing with complex or templated types.

   **Example**:
   ```cpp
   std::map<int, std::vector<int>> myMap;
   auto it = myMap.begin(); // Deduce the iterator type for the map
   ```

4. **Lambda Expressions**:
   - `auto` is commonly used in lambda expressions for type deduction.

   **Example** (Lambda):
   ```cpp
   auto add = [](int a, int b) { return a + b; };
   std::cout << add(2, 3);  // Output: 5
   ```

5. **Declaring `auto` with References or Pointers**:
   - `auto` can also be used with references or pointers, where the type is automatically deduced with the desired reference or pointer semantics.

   **Example**:
   ```cpp
   int x = 10;
   auto& ref = x;  // ref is a reference to int
   auto* ptr = &x; // ptr is a pointer to int
   ```

6. **Return Type Deduction (C++14 and Later)**:
   - In C++14 and later, the `auto` keyword can be used to automatically deduce the return type of a function.

   **Example** (Function return type deduction):
   ```cpp
   auto add(int a, int b) {
       return a + b;  // Return type is automatically deduced as 'int'
   }
   ```

---

### **Summary of Differences**:

| **Feature**               | **C**                            | **C++**                                        |
|---------------------------|----------------------------------|------------------------------------------------|
| **Primary Use**            | `auto` is used (historically) for automatic storage duration, but is largely obsolete in modern C. | **Type inference**: The type of a variable is automatically deduced by the compiler based on the initializer expression. |
| **Type Deduction**         | Not supported.                  | Supported: The type is inferred from the expression on the right-hand side of the assignment. |
| **Common Use**             | Rarely used in modern C.        | Commonly used with complex types (e.g., iterators, lambdas, STL containers). |
| **Compatibility**          | No support for type inference.  | Supports type inference for variables, return types, and iterators. |

---

### **Conclusion:**
- In **C**, the `auto` keyword is mostly obsolete and serves no real purpose in modern code.
- In **C++**, `auto` is a versatile and powerful feature that simplifies code by allowing the compiler to deduce the type of a variable or expression, making the code cleaner, more maintainable, and easier to write, especially when dealing with complex types like iterators or lambda functions.