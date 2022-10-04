#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *count_(void * args)
{
    int *arg = (int*) args;
    int n = arg[0];
    if (n == 1)
        n = 2;
    int m = arg[1];
    int count = 0;
    for(int i = n; i <= m; i++)
    {
        int flag = 0;
        for (int j = 2; j < i; j++)
        {
            if (n % i == 0)
                flag++;
        }
        if (flag == 0)
            count++;
    }
    printf("Number of primes between %d and %d is %d\n", n, m, count);
    int *ret = malloc(sizeof(int));
    *ret = count;
    return ret;
}

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int count = 0;
    int **ret = malloc(sizeof(int*));

    pthread_t pthreads[m];
    int args[m][2];
    for(int i = 0; i < m; i++)
    {
        args[i][0] = n/m*i+1;
        if (i == m-1)
            args[i][1] = n;
        else
            args[i][1] = n/m*(i+1);
        pthread_create(&pthreads[i], NULL, count_, (void *)&args[i]);
    }
    for(int i = 0; i < m; i++)
    {
        pthread_join(pthreads[i], (void **)ret);
        count += **ret;
    }
    printf("result:%d", count);
}
