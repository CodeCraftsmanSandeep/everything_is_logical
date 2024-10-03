#include <stdio.h>

int main(){
    int* ptr1, ptr2;
    int a = 100;
    ptr1 = &a;

    int b = 29;
    ptr2 = &b;

    printf("%d %d\n", *ptr1, *ptr2);
}
// catch the problem in this code!!
// this is a very different bug (infact one of the worst bugs)!!
// the same bug is there in C++