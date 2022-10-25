#include <stdio.h>
#include <stdlib.h>
int N;
int main()
{
    scanf("%d", &N);
    int *array = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        array[i] = i;
    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);
    free(array);
    return 0;
}
