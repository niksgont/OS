#include <stdio.h>

int TAT(int n, int ct[], int at[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = ct[i] - at[i];
}
int WT(int n, int ct[], int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];

}

int avgtime(int n, int bt[], int ct[], int at[])
{
    int wt[n], tat[n];
    double total_wt = 0.0, total_tat = 0.0;
    int i;
    TAT(n, ct, at, tat);
    WT(n, ct, bt, wt, tat);

    printf("Completed Waiting Turnaround \n");
    for (i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t %d\t %d\n", ct[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %f\nAverage Turnaround time: %f", total_wt / n, total_tat / n);
}
int main()
{
    int n;
    scanf("%d", &n);
    int bt[n], at[n], ct[n], pos[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
        pos[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);

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
                }
            }
        }
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }
    avgtime(n, bt, ct, at);
    return 0;
}
