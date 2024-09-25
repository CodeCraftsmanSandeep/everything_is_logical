#include <stdio.h>
#include <stdlib.h>

// Most of the C compilers support a third parameter to main which
// store all environment variables
int main(int argc, char *argv[]){
	for(int i = 1; i < argc; i++) printf("%d\n", atoi(argv[i]));
	printf("%d\n", atoi("1245sandeep")); // atoi converts longest valid prefix to integer

	char* str = "1234sdssdsd";
	char* endptr;
	int num = strtol(str, &endptr, 10);

	// strtol - string to long int
	// strtoll - string to long long int

	if(*endptr == '\0'){
		printf("No error\n");
		printf("%d\n", num);
	}else{
		printf("Error\n");
		printf("%d\n", num); // longest valid prefix is printed
	}

}