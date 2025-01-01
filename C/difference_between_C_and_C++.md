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