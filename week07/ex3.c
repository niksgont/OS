#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int n1 = 0;
    scanf("%d", &n1);
    int *a1 = (int *)malloc(n1 * sizeof(int));
    int i;
    for (i = 0; i < n1; i++)
    {
        a1[i] = 100;
        printf("%d ", a1[i]);
    }
    printf("\n");
    int n2 = 0;
    scanf("%d", &n2);
    a1 = realloc(a1, n2 * sizeof(int));
    for (int i = n1; i < n2; i++)
        a1[i] = 0;
    for (i = 0; i < n2; i++)
        printf("%d ", a1[i]);
    free(a1);
    return 0;
}
