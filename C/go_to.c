#include <stdio.h>

int main(){
    register int n = 0;

label:
    printf("%d ", n);
    if(++n < 10) goto label;

    printf("\n");

    return 0;
}