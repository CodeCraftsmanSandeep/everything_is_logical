#include <stdio.h>
#include <stdlib.h>

// Most of the C compilers support a third parameter to main which
// store all environment variables
int main(int argc, char *argv[]){
	for(int i = 1; i < argc; i++){
		printf("%d\n", atoi(argv[i]));
	}
	printf("%d\n", atoi("1245sandeep")); // atoi converts longest valid prefix to integer
}