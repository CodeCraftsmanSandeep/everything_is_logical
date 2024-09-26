#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*
stdin, stdout and stderr are treated as files and are already open with 
file discriptors 0, 1 and 2 respectively
*/

int main(){
    // writing to console
    // write system call: retuns the number of bytes written success
    size_t bytes_written = write(1, "Hi from OS code 1.\n", strlen("Hi from OS code 1.\n")); 
    if(bytes_written == -1){
        printf("Write system call failed\n");
        return 1;
    }
    printf("Bytes written = %zu\n", bytes_written);

    // O_CREAT - create file if it does not exist
    // O_WRONLY - write permission to file
    // O_RDONLY - read permission to file
    // O_RDWR - read and write permission 

    // S_IRUSR - read premission for owner
    // S_IWUSR - write permission for owner
    int fd = open("100_numbers.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR );
    if (fd < 0) {
        perror("Error opening a file");
        return 1;
    }
    char buff[10];
    for(int num = 1; num <= 100; num++){
        sprintf(buff, "%d\n", num);
        bytes_written = write(fd, buff, strlen(buff));
        if(bytes_written == -1){
            perror("Write system call failed\n");
            return 1;
        }
    }

    close(fd);
    return 0;
}