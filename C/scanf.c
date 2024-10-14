#include <stdio.h>

int main(){
    int num;
    // int return_val = scanf("%d\n", &num); // do not use \n in scanf here
    int return_val = scanf("%d%d", &num, &num); 
    printf("%d\n", return_val);

    printf("num = %d\n", num);
}

/*
Input:
1 10

Output:
2
num = 10

*/




/*
Input:
123djdfdf  1

Output:
1
123
*/

/*
Command:
./a.out < empty_file.txt

Output:
-1
num = 1

Notes:
scanf returned negative integer because it reached EOF while scanning
*/


/*
The scanf in C returns three types of values:

>0: The number of values converted and assigned successfully.
  0: No value was assigned.
<0: Read error encountered or end-of-file(EOF) reached before any assignment was made.
*/

