#include<stdio.h>

int main()
{
    int i, n, total = 0, x, counter = 0, time_quantum;

    scanf("%d", &n);
    int wt = 0, tat = 0, at[n], bt[n], temp[n], pos[n];
    float average_wait_time, average_turnaround_time;
    x = n;
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        pos[i] = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (at[j] < at[i])
            {
                int x = at[j];
                at[j] = at[i];
                at[i] = x;
                x = bt[j];
                bt[j] = bt[i];
                bt[i] = x;
                x = pos[j];
                pos[j] = pos[i];
                pos[i] = x;
                temp[i] = bt[i];
                temp[j] = bt[j];
            }
            if (at[j] == at[i])
            {
                if (pos[j] < pos[i])
                {
                    int x = at[j];
                    at[j] = at[i];
                    at[i] = x;
                    x = bt[j];
                    bt[j] = bt[i];
                    bt[i] = x;
                    x = pos[j];
                    pos[j] = pos[i];
                    pos[i] = x;
                    temp[i] = bt[i];
                    temp[j] = bt[j];
                }
            }
        }

    scanf("%d", &time_quantum);
    printf("Process\t Burst\t Turnaround\t Waiting\n");
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            x--;
            printf("%d\t %d\t %d\t %d\n", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
            wt = wt + total - at[i] - bt[i];
            tat = tat + total - at[i];
            counter = 0;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(i == n - 1)
        {
            i = 0;
        }
        else if(at[i + 1] <= total)
        {
            i++;
        }
    }

    average_wait_time = wt * 1.0 / n;
    average_turnaround_time = tat * 1.0 / n;
    printf("nnAverage Waiting Time:t%f", average_wait_time);
    printf("nAvg Turnaround Time:t%fn", average_turnaround_time);
    return 0;
}
