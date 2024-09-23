#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Geeks";
    printf("%d\n", sizeof(str));  // Size of the array

    printf("%lu\n", strlen(str));  // Length of the string

    str = "aj";

    char* temp = "Geeks";
    printf("%d\n", sizeof(temp));  // Size of the pointer

    // Use strlen to find the length of the string pointed by temp
    printf("%lu\n", strlen(temp));  // Length of the string

    return 0;
}
