#include <stdio.h>
#include <stdlib.h>

// scan disk scheduling

void main()
{

    int temp, headposition, work[100], p = 0, total=0, j, i;
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

    tracks[n + 2] = 199;
    tracks[n + 1] = 0;

    tracks[n] = head;
    n = n + 3;

    //Sorting
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
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
    // printf("Tracks are \n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d=>", tracks[i]);
    // }

    // int max = tracks[n - 1];

    for ( i = 0; i < n; i++)
    {
        printf("55");
        if (head == tracks[i])
        {
            headposition = i;
            break;
        }
    }
    if (head < (199 - head))
    {

        for (i = headposition; i >= 0; i--, p++)
        {
            // printf("%d", tracks[i]);
            work[p] = tracks[i];
        }
        for ( i = n - 1; i > headposition; i--, p++)
        {
            // printf("%d", tracks[i]);
            work[p] = tracks[i];
        }
    }
    else{
        for ( i = headposition; i < n; i++, p++)
        {
            // printf("%d", tracks[i]);
            work[p] = tracks[i];
        }
        for ( i = 0; i < headposition; i++, p++)
        {
            // printf("%d", tracks[i]);
            work[p] = tracks[i];
        }
    }
   

    for (i = 0; i < p; i++)
    {
        printf("%d", work[i]);
    }

    for ( j = 0; j < p - 1; j++)
    {
        int diff = 0;
        if (work[j] > work[j + 1])
        {
            diff = work[j] - work[j + 1];
        }
        else
        {
            diff = tracks[j + 1] - tracks[j];
        }
        total = total + diff;
    }

    printf("\b\b\b.  \nTOTAL HEAD MOVEMENTS : %d\n", total);

    // int sum = head + max;
    // printf("Total head movement is %d ", sum);
}