#include <stdio.h>
#include <string.h>

struct process
{
    char name[20];
    int at, tt, bt, wt, status, ct;
} p[20], temp;

struct done
{
    char name[20];
    int st, ct;
} d[20];

void main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter th process details:");
        printf("Process Name:");
        scanf("%s", p[i].name);
        printf("Arrival Time:");
        scanf("%d", &p[i].at);
        printf("Burst Time:");
        scanf("%d", &p[i].bt);
        p[i].status = 0;
    }

    // print process details
    // printf("Process\tArrival Time\tBurst Time\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%s\t\t%d\t\t%d", p[i].name, p[i].at, p[i].bt);
    //     printf("\n");
    // }
    int min, fnd, idle, num, ls;
    for (int i = 0, ls = 0, num = 0, idle = 0; ls < n;)
    {

        for (int j = 0, fnd = 0; j < n; j++)
        {
            if (i >= p[j].at && p[j].status == 0)
            {
                if (fnd == 0)
                {
                    min = j;
                    fnd = 1;
                }
                else if (fnd != 0 && p[j].bt < p[min].bt)
                {
                    min = j;
                }
            }
        }
        if (idle == 0 && fnd == 0)
        {
            strcpy(d[num].name, "idle");
            d[num].st = i;
            i++;
            idle = 1;
        }
        else if (fnd == 1)
        {
            if (idle == 1)
            {
                d[num].ct = i;
                num++;
                idle = 0;
            }
            strcpy(d[num].name, p[min].name);
            p[min].status = 1;
            d[num].st = i;
            d[num].ct = i + p[min].bt;
            i = d[num].ct;
            p[min].ct = i;
            p[min].tt = p[min].ct - p[min].at;
            p[min].wt = p[min].tt - p[min].bt;
            num++;
            ls++;
        }
        else
        {
            i++;
        }
    }
    int twt, ttt;
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
        twt += p[i].wt;
        ttt += p[i].tt;
        printf("\n");
    }
    printf("\nAVERAGE WAITING TIME : %d", (twt / n));
    printf("\nAVERAGE TURNAROUND TIME : %d\n", (ttt / n));
}
