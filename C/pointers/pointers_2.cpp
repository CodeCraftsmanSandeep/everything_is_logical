// function pointers in C
#include <stdio.h>

int add(int a, int b){
    return a + b;
}


int main(){
    int (*add_ptr)(int, int) = add;
    printf("%d\n", (add_ptr)(2, 3));
    
    return 0;
}