#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Expected input file name, output file name\n");
        exit(1);
    }
    const char* input_file_name = argv[1];
    const char* output_file_name = argv[2];

    int input_fd = open(input_file_name, O_RDONLY, S_IWUSR | S_IRUSR);
    if(input_fd < 0){
        printf("File open failed.\n");
        return 1;
    }

    int output_fd = open(output_file_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(output_fd < 0){
        printf("File open failed.\n");
        return 1;
    }

    // writing character by character is bad
    // so 1024 bytes of data is read everytime
    int buff_size = 1024;
    char buff[buff_size];
    int read_data;
    while((read_data = read(input_fd, buff, buff_size)) > 0){
        if(write(output_fd, buff, read_data) < 0){
            printf("Writing failed\n");
            return 1;
        }
    }

    return 0;
}