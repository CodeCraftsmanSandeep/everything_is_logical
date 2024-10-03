#include<stdio.h> 
int main() 
{ 
   int a; 
   char *x; 
   x = (char *) &a; 
   a = 512; 
   printf("%d\n",a);   
   x[1] = 1; 
   printf("%d\n",a);   
   x[0] = 1;
   printf("%d\n",a);    
   printf("%d\n",a);   
   return 0; 
}
