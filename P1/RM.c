#include<stdio.h>
int main(int argc, char *argv[])
{
if(remove(argv[1])==0)
printf("the file is succesfully deleted\n");
else
printf("unsuccesfull deletion\n");
}
