#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#define MAX 5
int in=0, out=0;
void *producer();
void *consumer();
sem_t empty,full;
int main()
{
 int i=0;
 pthread_t prod_id, cons_id;
 sem_init(&empty,0,MAX);
 sem_init(&full,0,0);
 pthread_create(&prod_id,NULL,producer,NULL);
 sleep(2);
 pthread_create(&cons_id,NULL,consumer,NULL);
 pthread_join(prod_id,NULL);
 pthread_join(cons_id,NULL);
 sem_destroy(&empty);
 sem_destroy(&full);
}
void *producer()
{
 int i,sleep_count;
 for(i=0;i<20;i++)
 {
 sem_wait(&empty);
 printf("Producer produced at %d\n",in);
 in = (in + 1) % MAX;
 //sleep_count=rand()%3;
 sleep(3);
 sem_post(&full);
 }
}
void *consumer()
{
 int i,sleep_count;
 for(i=0;i<20;i++)
 {
 sem_wait(&full);
 printf("\tConsumer consumed from %d\n",out);
 out = (out + 1) % MAX;
 //sleep_count=rand()%3;
 sleep(2);
 sem_post(&empty);
 }
}