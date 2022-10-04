#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


typedef struct Thread
{
    int id, i;
    char message[256];
} Thread;

void *Message(void*args)
{
    Thread *arg = (Thread*) args;
    printf("Thread %d: %s\n", arg->id, arg->message);
}

int main(void)
{
    Thread threads[10];
    pthread_t pthreads[10];
    for(int i = 0; i < 10; i++)
    {
        printf("Thread %d is created\n", i);
        threads[i].id = i;
        threads[i].i = i;
        sprintf(threads[i].message, "Hello from thread %d", i);
        pthread_create(&pthreads[i], NULL, Message, (void *)&threads[i]);
        pthread_join(pthreads[i], NULL);
    }
}
