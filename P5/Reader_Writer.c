#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<semaphore.h>
int readcount=0;
int count=0;
void *read_task();
void *write_task();
sem_t mutex,wrt;
int main()
{
 int i=0;
 pthread_t readid[10];
 pthread_t writeid;
 sem_init(&mutex,0,1);
 sem_init(&wrt,0,1);
 for(i=0;i<10;i++){
 pthread_create(&readid[i],NULL,read_task,NULL);
 if(i==4)
pthread_create(&writeid,NULL,write_task,NULL);
 }
 for(i=0;i<10;i++)
pthread_join(readid[i],NULL);
 pthread_join(writeid,NULL);
 sem_destroy(&mutex);
 sem_destroy(&wrt);
}
void *read_task()
{
 int fd;
 sem_wait(&mutex);
 readcount++;
 if(readcount==1)
 sem_wait(&wrt);
 char sentence[50];
 fd=open("a.txt",0);
 read(fd,sentence,30);
 printf("Reader %d reading\n",count++);
 printf("%s\n",sentence);
 sem_post(&mutex);
 close(fd);
 sem_wait(&mutex);
 readcount--;
 sleep(5);
 if(readcount == 0)
 sem_post(&wrt);
 sem_post(&mutex);
}
void *write_task()
{
 int fd;
 char sentence[50]="RV College of Engineering";
 sem_wait(&wrt);
 fd = open("a.txt",1);
 lseek(fd,SEEK_SET,30);
 write(fd,sentence,50);
 printf("Writer is writting\n");
 close(fd);
 sem_post(&wrt);
}