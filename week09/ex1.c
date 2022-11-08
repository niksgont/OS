#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    int size = atoi(argv[1]);
    FILE *file;
    file = fopen("input.txt", "rt");

    int *frames = (int*)calloc(size, sizeof(int));
    memset(frames, 0, size);
    int *ages = (int*)calloc(size, sizeof(int));
    memset(ages, 0, size);
    int cur, miss = 0, hit = 0;
    while (fscanf(file, "%d", &cur) != EOF)
    {
        int num_of_frame = -1;
        for (int i = 0; i < size; i++)
            if (cur == frames[i])
            {
                num_of_frame = i;
                break;
            }
        if (num_of_frame != -1)
        {
            hit++;
            ages[num_of_frame] >>= 1;
            ages[num_of_frame] |= 1<<7;
        }
        else
        {
            miss++;
            int min = 0;
            for (int i = 0; i < size; i++)
                if (ages[i] < ages[min])
                    min = i;
            frames[min] = cur;
            ages[min] = 0;
            ages[min] |= 1 << 7;

        }
    }
    printf("Hit rate: %d\nMiss rate :%d\n", hit, miss);
    if (miss != 0)
        printf("Hits/Misses ratio: %lf", (double)hit/(double)miss);
    fclose(file);
    return 0;
}
