
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int at[n], bt[n], tat[n], wt[n], ct[n];
    float total_tat = 0.0, total_wt = 0.0;
    int i, smallest, count = 0, time;
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (at[j] < at[i])
            {
                int x = at[j];
                at[j] = at[i];
                at[i] = x;
                x = bt[j];
                bt[j] = bt[i];
                bt[i] = x;
            }
    smallest = 0;
    printf("Process Completed Waiting Turnaround \n");
    for(time = 0; count != n; time++)
    {
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
            {
                smallest = i;
            }
        }

        count++;

        ct[smallest] = time + bt[smallest];
        wt[smallest] = ct[smallest] - at[smallest] - bt[smallest];
        tat[smallest] = ct[smallest] - at[smallest];
        printf("%d\t %d\t %d\t %d\n", smallest + 1, ct[smallest], wt[smallest], tat[smallest]);
        total_wt = total_wt + wt[smallest];
        total_tat = total_tat + tat[smallest];
        time+=  bt[smallest] - 1;
        bt[smallest] = 9999;
    }




    printf("Average waiting time: %f\nAverage Turnaround time: %f", total_wt / n, total_tat / n);
    return 0;
}
