
#include <stdio.h>

int g = 10;

// C program that demonstrated wild pointers
int main()
{
	/* wild pointer */
	int* p;
	/* Some unknown memory location is being corrupted.
	This should never be done. */
	// *p = 12;
}