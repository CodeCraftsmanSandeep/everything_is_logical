// we can also use #include <stdio.h>
// but its better to you cstdio, to get a clear identification that it is C library
#include <cstdio> 

void print(int x){
    printf("%d\n", x);
}

void print(double x){
    printf("%f\n", x);
}

int main(){
    print(2);
    print(2.3);
}