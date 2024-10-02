# Introudction
- C is a procedural language.
- C++ is primarily an object-oriented programming (OOP) language, but it also supports procedural programming. This means that C++ is a multi-paradigm language, combining both procedural and object-oriented features, along with other paradigms like generic and functional programming.
- Main differences in C and C++
    - C++ supports OOPs paradigm while C only has the procedural concept of programming.
    - C++ has exception handling capabilities. In C, we have to resolve exceptions manually.
    - There are no references in C.
- C/C++ are **statically typed languages**.
    - This means that the data type of each variable is known at compile time. You must declare the type of every variable (e.g., int, float, char) before you use it, and the type cannot change at runtime.
- In contrast, dynamically typed languages determine the data types of variables at runtime, and variables can change their type during execution (e.g., Python, JavaScript).
- C and C++ are fast because statically typed languages are faster than dynamically typed languages.
- C/C++ are general purpose languages.
    - SQL, HTML, Verilog are not general purpose programming languages.
- Mid, Low, High level languages
    - High level languages
        - Python, Java
    - Mid level languages
        - C, C++
    - Low level languages
        - Assembly languages
        - Machine code
- auto keyword is present in C but is redundant. 
    - auto in C and C++ are completely different.
- qsort() in C
    - ```cpp void qsort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *)); ```

# Contents
1) static libraries and dynamic libraries
    - [Article](https://www.geeksforgeeks.org/static-vs-dynamic-libraries/)
    - [Article](https://www.geeksforgeeks.org/static-and-dynamic-linking-in-operating-systems/?ref=asr2)
2) [Static functions in C](https://www.geeksforgeeks.org/what-are-static-functions-in-c/)
3) [static variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
    - static variables are initialized with zero, if not explicitly initialized.
    - static variables and global variables are stored in data segment.
4) [Memory layout of C program](https://www.geeksforgeeks.org/memory-layout-of-c-program/)
5) [Printing environment variables in C](https://www.geeksforgeeks.org/c-program-print-environment-variables/)
    - Environment variables are dynamic values that affect the behavior of processes running on an operating system. They provide a way to store configuration information that can be used by both system processes and user applications. These variables are usually used to define system-wide settings, such as file paths, language preferences, and system-specific options, without hardcoding them into scripts or applications.
6) Conversions
    - string to integer
        - atoi and strtol, strtoll: [atoi_strtol.c](atoi_strtol.c)
        - strtol is safer to use.
    - integer to string conversion
        - can be done by using sprintf.
7) printf 
    - [printf.c](printf.c)
    - [GFG Article](https://www.geeksforgeeks.org/printf-in-c/)
8) sprintf
    - [sprintf.c](sprintf.c)
    - sprintf stand for string print.
9) scanf
    - scanf stands for scan fromatted string.
10) format specifiers in C
    - [GFG Article](https://www.geeksforgeeks.org/format-specifiers-in-c/)
11) [enums](https://www.geeksforgeeks.org/enumeration-enum-c/)
    - An enum is a user-defined type that consists of a set of named integer constants.
11.1) Macros
12) extern 
13) [register](https://www.geeksforgeeks.org/understanding-register-keyword/)
14) Operators in C:
    - ![alt text](operators_in_c.png)

## Strings
- [strings_1.c](strings_1.c)
- strcpy

## Pointers
- A pointer is defined as a derived data type that can store the address of other C variables or a memory location. We can access and manipulate the data stored in that memory location using pointers.
- Types of pointers
    - NULL pointer:
        - [Article on uses of null pointers.](https://www.geeksforgeeks.org/null-pointer-in-c/)
        - Definition of NULL:
            - NULL is defined as <br/> ```cpp #define NULL ((void*)0) ```
            - It represents a pointer that does not point to any valid object or function. The ((void*)0) means a pointer to the memory address 0, which is reserved by most operating systems to indicate an invalid address.
    - Wild pointers:
        - Pointers which are not yet initilized.
        - Playing with wild pointers may lead to crashes and unexpected behaviour.
        - [Article on: What are wild pointers and how we can avoid them](https://www.geeksforgeeks.org/what-are-wild-pointers-how-can-we-avoid/)
    - Void pointers:
        - A void pointer is a pointer that has no associated data type with it. A void pointer can hold an address of any type and can be typecasted to any type.
        - advantages of void*
            - malloc() and calloc() return void * type and this allows these functions to be used to allocate memory of any data type (just because of void *)
- function overloading in C
- pointer arithmetic
    - Pointer Arithmetic is the set of valid arithmetic operations that can be performed on pointers.
- Pointers can be outputted using %p, since, most of the computers store the address value in hexadecimal form using %p gives the value in that form. But for simplicity and understanding we can also use %u to get the value in Unsigned int form.
- Array decay, which happens in C and C++.
    - [GFG article](https://www.geeksforgeeks.org/what-is-array-decay-in-c-how-can-it-be-prevented/)





# Some questions
- [question_1.png](question_1.png)


<!-- 
- TO DO:
- error handling in C
- operator overloading in C
- variable arguments to functions in C
- pointer arthimetic
-->