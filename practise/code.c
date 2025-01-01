#include <stdio.h>
#include <stdlib.h>

int main(){
    // int* num = (int *)malloc(1 * sizeof(int));
    int* num = (int *)calloc(1, sizeof(int));

    printf("Num = %d\n", *num);
}