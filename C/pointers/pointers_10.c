#include <stdio.h>

int main(){
    int a = 10;
    const int* a_ptr = &a;

    // *a_ptr = 100; // this is invalid, because a_ptr has read only permissions to a
    a = 100;
    printf("%d %d\n", a, *a_ptr);
    
    const int b = -209;
    int* b_ptr = &b;

    *b_ptr = 1000000;
    printf("%d %d\n", b, *b_ptr); // the output is not predicatbale 
    // it depedns on compiler

}