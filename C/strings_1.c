#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Geeks";
    printf("%d\n", sizeof(str));  // Size of the array

    printf("%lu\n", strlen(str));  // Length of the string

    // str = "aj"; // cannot be reassigned
    str[0] = 'b'; // this is safe
    printf("%s\n", str);

    char* temp = "Geeks";
    printf("%d\n", sizeof(temp));  // Size of the pointer

    temp = "sandeep"; // can be re-assigned
    // temp[0] = 'f'; // this is invalid, as the string is present in read-only section in memory

    // Use strlen to find the length of the string pointed by temp
    printf("%lu\n", strlen(temp));  // Length of the string

    return 0;
}
