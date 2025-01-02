#include <stdio.h>

int identity_int(int x){
    return x;
}

float identity_float(float x){
    return x;
}

double identity_double(double x){
    return x;
}

#define call(x) _Generic((x), \
    int: identity_int(x), \
    float: identity_float(x), \
    double: identity_double(x) )

int main(){
    int num_int = 10;
    float num_float = 10.23;
    double num_double = 10.45;

    printf("%d\n", call(num_int));
    printf("%.3f\n", call(num_float));
    printf("%.3f\n", call(num_double));

    return 0;
}