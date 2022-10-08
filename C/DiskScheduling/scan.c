#include <stdio.h>
#include <stdlib.h>

// scan disk scheduling

void main()
{

    int temp, headposition;
    printf("Enter the number of tracks");
    int n;
    scanf("%d", &n);
    int tracks[n];
    printf("Enter the tracks");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the head position");
    int head;
    scanf("%d", &head);
    int newhead = 0;
    int sum_seek = 0;

    tracks[n] = head;
    n = n + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (tracks[i] > tracks[j])
            {
                temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }
    // print track
    printf("Tracks are \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d=>", tracks[i]);
    }

    int max = tracks[n - 1];

    for (int i = 0; i < n; i++)
    {
        if (head == tracks[i])
        {
            headposition = i;
            break;
        }
    }

    for (int i = headposition; i >= 0; i--)
    {
        printf("%d", tracks[i]);
    }
    for (int i = headposition; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", tracks[i]);
        }
        else
            printf("%d->", tracks[i]);
    }
    int sum = head + max;
    printf("Total head movement is %d ", sum);
}