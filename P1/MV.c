#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
 int fd1,fd2,n;
char buffer[20];
if(argc!=3)
{
printf("unsuccessfull move\n");
exit(0);
}
fd1=open(argv[1],O_RDONLY);
fd2=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC|O_EXCL,0600);
while((n=read(fd1, buffer, 20))!=0)
write(fd2, buffer, n);
close(fd1);
close(fd2);
if(remove(argv[1])==0)
printf("the file is succesfully moved\n");
else
printf("unsuccesfull move\n");
}