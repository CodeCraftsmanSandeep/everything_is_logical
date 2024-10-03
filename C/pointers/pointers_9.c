// code on constant pointers
// very annoying code
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 100;
    int * const a_ptr = &a;

    *a_ptr = 2010; // this is valid because the pointer is not pointing to constant variables
    printf("%p, %d, %d\n", a_ptr, *a_ptr, a);
    

    int b = 200;
    int* b_ptr = &b;
    // a_ptr = &b; // this is invalid as a_ptr is a constant pointer, it can only point to a
    
    // Incorrect use of free:
    // The free function is used to deallocate memory allocated with malloc, calloc, or realloc. 
    // In your code, a_ptr is not a pointer to dynamically allocated memory, 
    // but a pointer to a local variable. Attempting to free it will result in undefined behavior.
    // free(a_ptr);


    // double pointer pointintg to constant pointer

    int** ptr_ptr = &a_ptr;
    printf("%p %p %d\n", ptr_ptr, *ptr_ptr, **ptr_ptr);
    *ptr_ptr = &b; // this is valid !!
    // This violates the constant pointer restriction on a_ptr, as a_ptr was declared as int * const. 
    // However, this code will compile without errors because modifying *ptr_ptr directly bypasses this restriction.

    printf("%p %d\n", a_ptr, *a_ptr);
}