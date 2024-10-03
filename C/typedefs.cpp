#include <stdio.h>

// typedefs of strctures
typedef struct LinkedListNode{
    int data;
    struct LinkedListNode* next;
} node;


// typedefs in enums
typedef enum gender {Man, Woman} gen;

// typedefs for kepping my own names to data types
typedef int* Int_ptr;
#define int_ptr int*


int main(){
    gen obj = Man;
    printf("%d\n", obj);

    Int_ptr x, y;
    int_ptr a, b;

    printf("%d %d\n", sizeof(x), sizeof(y));
    printf("%d %d\n", sizeof(a), sizeof(b));

    // Note the difference between type defs and #defines
}