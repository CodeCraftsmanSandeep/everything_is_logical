#include <stdarg.h>
#include <stdio.h>

int addNumbers(int n, ...){
    va_list ptr;

    va_start(ptr, n);

    int sum = 0;
    for(int i = 0; i < n; i++) sum += va_arg(ptr, int);
    va_end(ptr);

    return sum;
}
int main(){
    printf("Sum = %d\n", addNumbers(4, 1, 2, 3, 4));
}