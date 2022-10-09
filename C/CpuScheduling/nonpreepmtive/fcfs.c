#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], i;
    float awt = 0, atat = 0;
    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
    for (i = 0; i < n; i++)
    {
        awt += wt[i];
        atat += tat[i];
    }
    awt /= n;
    atat /= n;
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time: %f",awt);

    printf("Average Turn Around Time: %f",atat);
}