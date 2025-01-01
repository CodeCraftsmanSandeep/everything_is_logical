// different type of string operations in C
#include <stdio.h>
#include <string.h>

int main(){
    char* str1 = "sandeep reddy";
    char copy_str[strlen(str1) + 1];
    strcpy(copy_str, str1);
    printf("%s, %s\n", copy_str, str1);

    char another_copy[strlen(str1) + 1];
    sprintf(another_copy, "%s", str1);
    printf("%s\n", another_copy);

    printf("%d\n", strcmp(str1, another_copy));
    printf("%d\n", strcmp("amma", "nanna")); // returns a negative number
}