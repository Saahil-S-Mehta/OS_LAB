#include <stdio.h>
#include "add.c"
#include "sub.c"
int main()
{
int a = 5, b = 7;
printf("\nThe sum is : %d", add(a,b));
printf("\nThe difference is : %d \n",sub(a,b));
return 0;
}
