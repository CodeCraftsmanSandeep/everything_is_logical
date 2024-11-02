### sprintf is depericated and only supported for compatibility reasons
- Source: see ```man sprintf```
- Example inidicating the problem with sprintf:
    - ```c
        #include <stdio.h>

        int main(){
            char* name = "Hi, Good Morning!!";
            char buff[10];
            sprintf(buff, "%s", name);
            printf("%s\n", buff);
        }
    ```
    - Some compilers do output: ```Hi, Good Morning!!```, which should not be actually, as buffer size is only 10.
    - See man pages for reasons.
- Use of snprintf
    - ```c
        #include <stdio.h>

        int main(){
            char* name = "Hi, Good-Morning!!";
            char buff[10];
            int output;
            if((output = snprintf(buff, 10, "%s", name)) >= 10){
                // maximum characters allowed is only 9, last slot is for '\0'
                printf("More characters are there in name and are discarded, output = %d\n", output);
            }
            printf("%s\n", buff);
        }
    ```
    - Compiler output:
        - ``` 
            More characters are there in name and are discarded, output = 18
            Hi, Good-
        ```