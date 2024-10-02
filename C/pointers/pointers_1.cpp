#include <stdio.h>

int main(){
    int* int_ptr;
    char* char_ptr;

    // As the pointers in C store the memory addresses, their size is independent of the type of data 
    // they are pointing to. This size of pointers in C only depends on the system architecture.

    printf("%d %d\n", sizeof(int_ptr), sizeof(char_ptr));

    int arr[] = {10, 1, 2};
    int* ptr = arr;
    printf("%d %d\n", *arr, *ptr); // arr is a pointer pointing to first element in array
    printf("%d %d\n", arr, ptr);       
}