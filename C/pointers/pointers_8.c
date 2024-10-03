#include <stdio.h>

int main(){
    int n = 4;
    int arr[] = {100, 2, 3, 4};

    int* ptr = (arr + 2);
    printf("%d\n", (ptr[-1]));
}