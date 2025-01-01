#include <stdio.h>

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