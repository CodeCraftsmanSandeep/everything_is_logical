#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Expected command line args: even/odd, range_begin and range_end\n");
        exit(1);
    }
    int range_begin = atoi(argv[2]);
    int range_end = atoi(argv[3]);

    if(strcmp(argv[1], "even") == 0){
        // print even numbers
        int fd = open("even.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
        if(fd < 0){
            printf("File open failed.\n");
            exit(1);
        }
        char buff[25];
        for(int i = range_begin; i <= range_end; i++){
            if((i&1) == 0){
                sprintf(buff, "%d\n", i);
                write(fd, buff, strlen(buff));
            }
        }
    }else if(strcmp(argv[1], "odd") == 0){
        // print odd numbers
        int fd = open("odd.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
        if(fd < 0){
            printf("File open failed.\n");
            exit(1);
        }
        char buff[25];
        for(int i = range_begin; i <= range_end; i++){
            if((i & 1) == 1){
                sprintf(buff, "%d\n", i);
                write(fd, buff, strlen(buff));
            }
        }
    }else{
        printf("Invalid command line argument\n");
        exit(1);
    }
    return 0;
}