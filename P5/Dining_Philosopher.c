#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int state[5];
sem_t self[5];
void *philosopher(void *num);
void pickup(int);
void test(int);
void putdown(int);
int phil_no[5]={0,1,2,3,4};
int main()
{
 int i,k;
 pthread_t tid;
 for(i=0;i<5;i++){
 state[i]=0;
 sem_init(&self[i],0,1);
 }
 for(i=0;i<10;i++){
 k= i % 5;
 pthread_create(&tid,NULL,philosopher,&phil_no[k]);
 sleep(1);
 }
 pthread_join(tid,NULL);
 for(i=0;i<5;i++)
 sem_destroy(&self[i]);
}
void *philosopher(void *num)
{
 int *i=num;
 pickup(*i);
 sleep(10);
 putdown(*i);
 printf("Philosopher %d is putdown\n",*i);
}
void pickup(int i)
{
 state[i]=1;
 test(i);
 if(state[i]!=2)
 sem_wait(&self[i]);
}
void test(int i)
{
 printf("states in test are %d:%d %d:%d
%d:%d\n",i,state[i],(i+1)%5,state[(i+1)%5],(i+4)%5,state[(i+4)%5]);
 if(state[i]==1 && state[(i+1)%5] != 2 && state[(i+4)%5] != 2){
 state[i]=2;
 printf("Philosopher %d is eating\n",i);
 sem_post(&self[i]);
 }
}
void putdown(int i)
{
 state[i]=0;
 test((i+1)%5);
 test((i+4)%5);
}