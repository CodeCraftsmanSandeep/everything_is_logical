#include "stdio.h"

typedef int (*funPtr)(int);

int inc(int a)
{
 printf("Inside inc() %d\n",a);
 return (a+1);
}

int main()
{

 funPtr incPtr1 = NULL, incPtr2 = NULL;

 incPtr1 = &inc; /* (1) */
 incPtr2 = inc; /* (2) */

 (*incPtr1)(5); /* (3) */
 incPtr2(5); /* (4)*/

 int n = 10;
 const int x = n;
 constexpr int y = n;
 
 return 0;
}
