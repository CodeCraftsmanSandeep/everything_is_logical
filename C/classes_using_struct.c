#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

struct arthimetic{
    int (*add_ptr)(int, int);
    int (*sub_ptr)(int, int);
    int (*mul_ptr)(int, int);
};

int main(){
    struct arthimetic *obj = (struct arthimetic *)malloc(1 * sizeof(struct arthimetic));
    obj->add_ptr = &add;
    obj->sub_ptr = &sub;
    obj->mul_ptr = &mul;

    printf("Add result = %d\n", obj->add_ptr(4, 2));
    printf("Sub result = %d\n", obj->sub_ptr(4, 2));
    printf("Mul result = %d\n", obj->mul_ptr(4, 2));
}