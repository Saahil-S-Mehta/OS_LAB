#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
int a,b,c;
a = atoi(argv[1]);
b = atoi(argv[2]);
c= a+b;
printf("The value of argc is %d\n",argc);
printf("The value of c is %d\n",c);
exit(0);
}
