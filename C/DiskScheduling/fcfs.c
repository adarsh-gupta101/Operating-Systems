#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int n, head, tracks[20], newhead = 0, sum_seek = 0;
    printf("Enter the total number of tracks");
    scanf("%d", &n);
    printf("Enter the head position");
    scanf("%d", &head);
    printf("Enter all the tracks");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }

    for (int i = 0; i < n; i++)
    {
        newhead = abs(head - tracks[i]);
        head=tracks[i];
        sum_seek = sum_seek + newhead;
    }

    // Traversed order

    printf("Traversed order is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", tracks[i]);
        printf("\n");
    }
    printf("Total seek time is %d", sum_seek);
}
