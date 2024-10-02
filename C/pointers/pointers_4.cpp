// void pointers
#include <stdio.h>

void* add(void* a, void* b){
    static int c = *(int*)a + *(int*)b; // static is needed
    return &c;
}

int main(){
    int a = 10;
    double b = 100.982;
    char ch = 'L';

    void *void_ptr;
    
    void_ptr = &a;
    // printf("%d\n", *void_ptr); // this is invalid as void pointer cannot be dereferenced

    printf("%d\n", *((int*)void_ptr));

    void_ptr = &b;
    printf("%.5f\n", *((double*)void_ptr));

    void_ptr = &ch;
    printf("%c\n", *((char *)void_ptr));

    int n = 3;
    int arr[3];
    arr[0] = 10;
    arr[1] = 100;
    arr[2] = 9;
    printf("%p %p\n", arr, &arr); // these both values are same
    // but arr is pointer to first element
    // & arr is pointer to entire array

    // ---------------------------------------------------------------------
    const int size = 2; // if const is not there the following code will fail
    int new_arr[size];
    new_arr[0] = 100;
    new_arr[1] = 1000;
    int (*new_ptr)[size] = &new_arr;
    printf("%d\n", (*new_ptr)[1]);
    // ---------------------------------------------------------------------

    int num1 = 10;
    int num2 = 9;
    int* result = (int*)add(&num1, &num2);
    printf("%d\n", *result);
}

