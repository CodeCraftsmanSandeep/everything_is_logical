#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "w";
    char str2[] = "W";
    
    int result = strcmp(str1, str2);
    
    if (result == 0) {
        printf("Strings are equal.\n");
    } else if (result < 0) {
        printf("str1 is less than str2.\n");
    } else {
        printf("str1 is greater than str2.\n");
    }
    
    return 0;
}