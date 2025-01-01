#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5;
    
    int* arr_1 = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr_1[i] = i + 1;
    }

    int* copy_arr = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        copy_arr[i] = arr_1[i];
    }

    int large_n = 10;
    copy_arr = (int*)realloc(copy_arr, large_n * sizeof(int)); // reallocating memory
    for(int i = n; i < large_n; i++){
        copy_arr[i] = 100;
    }

    printf("Elements in copy_arr:\n");
    for(int i = 0; i < large_n; i++){
        printf("%d ", copy_arr[i]);
    }
    printf("\n");
}