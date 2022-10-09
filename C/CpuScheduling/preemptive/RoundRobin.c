#include <stdio.h>
#include <string.h>

struct process
{
    char name[20];
    int at, tt, bt, wt, status, ct, left;
} p[20], temp;

struct done
{
    char name[20];
    int st, ct;
} d[20];

int q[100], front = -1, rear = -1;

void enqueue(int x)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    q[rear] = x;
}

int dequeue()
{
    int x = q[front];
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return x;
}

void main()
{
    int n, idle = 0, k;
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
        p[i].left = p[i].bt;
        p[i].status = 0;
    }

    // print process details
    // printf("Process\tArrival Time\tBurst Time
    printf("Enter Time Quanta:");
    int tq;
    scanf("%d", &tq);

    for (int i = 0, num = 0, ls = 0; ls < n;)
    {

        for (int j = 0; j < n; j++)
        {
            if (p[j].at <= i && p[j].status == 0)
            {
                enqueue(j);
                p[j].status = 1;
            }
        }
        if (idle == 0 && front == -1)
        {
            strcpy(d[num].name, "idle");
            d[num].st = i;
            idle = 1;
            i++;
        }
        else if (front != -1)
        {
            if (idle == 1)
            {

                d[num].ct = i;
                idle = 0;
                num++;
            }
            k = dequeue();
            d[num].st = i;
            strcpy(d[num].name, p[k].name);
            if (p[k].left <= tq)
            {
                d[num].ct = i + p[k].left;
                p[k].ct = d[num].ct;
                i = d[num].ct;
                p[k].tt = i - p[k].at;
                p[k].wt = p[k].tt - p[k].bt;
                p[k].status = 2;
                ls++;
                num++;
            }
            else if (p[k].left > tq)
            {
                d[num].ct = i + tq;
                i = d[num].ct;
                p[k].left = p[k].left - tq;
                num++;
                for (int j = 0; j < n; j++)
                {
                    if (p[j].status == 0 && p[j].at <= i)
                    {
                        enqueue(j);
                        p[j].status = 1;
                    }
                }
                enqueue(k);
            }
        }
        else
            i++;
    }
    int avwt = 0, avtt = 0;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
        avwt += p[i].wt;
        avtt += p[i].tt;
    }
    printf("Average Waiting Time: %d", avwt / n);
    printf("Average Turn Around Time: %d", avtt / n);
}
