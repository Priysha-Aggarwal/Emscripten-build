#include<stdio.h>
#include<pthread.h>
#include<string.h>
 
pthread_t tid[2];
 
void* sayhello(void *arg)
{
    printf("\n Hello from thread %d\n",*((int*)arg));
    return NULL;
}
 
int main(void)
{
    int i = 0;
    int error;
    while(i < 2)
    {
        error = pthread_create(&(tid[i]), NULL, &sayhello, &i);
        if (error != 0)
            printf("\nThread can't be created :[%s]", strerror(error));
        i++;
    }
 
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}
