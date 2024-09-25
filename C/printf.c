#include <stdio.h>
#include <stdint.h>

int main(){
    int n = 100;
    int return_value = printf("n = %d\n", n);
    printf("%d\n", return_value);

    printf("\n");

    // printing special characters
    printf("Percentage symbol: %% \n");
    printf("Slash: \\ \n");
    printf("New line: \\n \n");
    printf("Tab: \\t \n");

    printf("\n");

    char* str = "sandeep";
    printf("My name is: %30s\n", str);

    char * friend = "sandeep reddy chekkala";
    int ret = printf("My name is: %30s\n", friend);
    printf("%d\n", ret);

    printf("\n");
    // precision

    printf("%.10d\n", 1000);        // leading zeros are added
    printf("%.2f\n", 10.20189);     // precision 
    printf("%.4s\n", "sandeep");    // specifying the length of string

    printf("%10.2Lf\n", 1000.2345);
    printf("%20.15ld\n", 1234567890);
    
    printf("\n");

    // safe way to convert pointer to integer and vice versa
    int*  ptr = &n;
    uintptr_t int_ptr = (uintptr_t)ptr;

    // all the three has same value
    printf("%p\n", int_ptr);
    printf("%p\n", ptr);
    printf("%p\n", &n);

    printf("\n");

    // printing a string character by character
    char string[] = "sad red";
    int i  = 0;
    while(string[i] != '\0') printf("%c", string[i++]);
    printf("\n");

    char* temp = "mac windows";
    i = 0;
    while(temp[i] != '\0') printf("%c", temp[i++]);
    printf("\n");
}

/*
printf
    returns the number of characters succesfully printed on console.
    else returns negative number if it is not successful.
*/