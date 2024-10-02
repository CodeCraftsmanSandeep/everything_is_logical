// pointer arthemtic
#include <stdio.h>

// The loss of type and dimensions of an array is known as decay of an array. 
void func(double arr[]){
    // When you pass arr to the function func, 
    // it decays to a pointer to its first element, 
    // and the size of the pointer arr inside func will also be the 
    // size of the pointer, not the array itself.

    printf("size = %u\n", sizeof(arr));
}

int main(){
    double arr[] = {10.1, 22.11, 100, -1};
    const int n = sizeof(arr) / sizeof(arr[0]);

    // iterating with indexing
    for(int i = 0; i < n; i++) printf("%.3f ", arr[i]);
    printf("\n");

    // iterating with pointers
    for(int i = 0; i < n; i++) printf("%.3f ", *(arr + i));
    printf("\n");

    printf("-------\n");

    // printing by advancing pointer
    double* ptr = arr;
    // When a pointer is incremented, it actually increments by the number 
    // equal to the size of the data type for which it is a pointer. 
    for(int i = 0; i < n; i++) printf("%u, %.3f\n", ptr, *(ptr++)); 
    
    printf("-------\n");
    // printing elements which are at even indices in arr
    ptr = arr;
    while(ptr < arr + n){
        printf("%.3f ", *(ptr));
        ptr += 2;
    }
    printf("\n");

    printf("-----\n");
    double* new_ptr = arr;
    printf("size = %u\n", sizeof(new_ptr));
    printf("size = %u\n", sizeof(arr)); // 8 * 4, because double takes 8 bytes of storage and there are 4 elements in the arr
    func(arr);
}