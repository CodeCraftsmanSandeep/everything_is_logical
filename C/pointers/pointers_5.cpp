// q sort
#include <stdio.h>
#include <stdlib.h>


int compare(const void * a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int n = 3;
    int arr[] = {10, 2, 1};
    qsort(arr, 3, sizeof(int), compare);

    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}