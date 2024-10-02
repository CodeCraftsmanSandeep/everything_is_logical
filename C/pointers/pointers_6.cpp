#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int main(){
    int n = 5;
    int * arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Error: Memory allocation failed\n");
        return 1;
    }
    arr[0] = 10;
    arr[1] = 100;
    arr[2] = -10;
    arr[3] = 100;
    arr[4] = -3;
    printf("%d\n", arr[4]);
    free(arr);
    printf("%d\n", arr[4]);


    printf("--------\n");

    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    printf("%d\n", *ptr);
    free(ptr);
    printf("%d\n", *ptr);

    printf("--------\n");
    
    char ch = '1';

    int (*func_pointers[])(int, int) = {add, subtract, multiply};
    int a = 10;
    int b = 1;

    switch(ch){
        case('0'):
            // addition
            printf("After adding: %d\n", func_pointers[0](a, b));

        case('1'):
            // subtraction
            printf("After subtraction: %d\n", func_pointers[1](a, b));

        case('2'):
            // multiplication
            printf("After multiplication: %d\n", func_pointers[2](a, b));

        default:
            printf("Its a default thing!!\n");
    }

    // expect the output 
}