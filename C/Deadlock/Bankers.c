#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int allocs[n][m], maxs[n][m], need[n][m], avails[m], work[m], finish[n];

    int alloc[5][3] = {{0, 1, 0},  // P0    // Allocation Matrix
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4

    int max[5][3] = {{7, 5, 3},  // P0    // MAX Matrix
                     {3, 2, 2},  // P1
                     {9, 0, 2},  // P2
                     {2, 2, 2},  // P3
                     {4, 3, 3}}; // P4

    int avail[3] = {3, 3, 2}; // Available Resources

    // printf("Enter the allocation matrix:");
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < m; j++)
    //     {
    //         scanf("%d", &alloc[i][j]);
    //     }
    // }
    // //  for(i=0;i<n;i++){
    // //     for(j=0;j<m;j++){
    // //         printf("%d",alloc[i][j]);
    // //     }

    // // }
    // printf("Enter the max matrix:");
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < m; j++)
    //     {
    //         scanf("%d", &max[i][j]);
    //     }
    // }
    // //
    // printf("Enter the available matrix:");
    // for (i = 0; i < m; i++)
    // {
    //     scanf("%d", &avail[i]);
    // }
    printf("Need Matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("Need matrix [i][j]%d ", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    int DONE = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    // printf("p%d", i);
                    work[DONE++] = i;

                    for (int y = 0; y < m; y++)
                    {
                        avail[y] = avail[y] + alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {

            printf("System is in unsafe state");
            break;
            return 0;
        }
    }

    // print work matrix
    printf("Work Matrix is:\n");
    for (i = 0; i < n; i++)
    {
        printf("Work matrix [i][j]%d ", work[i]);
    }
    printf("\n");


    for (i = 0; i < n - 1; i++)
    {
        /* code */
        printf("p%d->", work[i]);
    }
    printf("p%d", work[n-1]);

    // printf("System is in safe state");
}
