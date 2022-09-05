#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
pid_t pid;
pid = fork();
if(pid==0){
printf("Its a child Process\n");
execl("add","add",argv[1],argv[2], (char *)0);
exit(0);
}
else{
wait(0);
printf("Its a Parent Process\n");
exit(0);
}
}