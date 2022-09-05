#includestdio.h
#includestdlib.h
#includepthread.h
int sum = 0;
void fun1(void arg)
{
int n = atoi(arg);
int i;
for(i=1;i=n;i++)
sum = sum + i;
pthread_exit(0);
}
int main(int argc, char argv[])
{
pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid, &attr, fun1, argv[1]);
pthread_join(tid, NULL);
printf(Sum updated from thread is %dn,sum);
exit(0);
}