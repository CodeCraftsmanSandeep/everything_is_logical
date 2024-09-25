#include <stdio.h>

int main(){
    char* str = "sandeep reddy";
    char buffer[50];

    int return_val = sprintf(buffer, "My name: %s\n", str);
    printf("Return value from sprintf = %d\n", return_val);
    return_val = printf("%s", buffer);
    printf("Return value from printf = %d\n", return_val);
}