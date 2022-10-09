#include <stdio.h>
#include <stdlib.h>

void main()
{
    int max, loc;

    printf("Enter the number process");
    int number;
    scanf("%d", &number);
    int process[number];
    int size[number];
    int i;
    for (i = 0; i < number; i++)
    {
        printf("Enter the size of process %d", i + 1);
        scanf("%d", &size[i]);
    }
    int memory;
    printf("Enter the number of memory");
    scanf("%d", &memory);
    int memory_size[memory];

    int memory_process[memory];
    for (i = 0; i < memory; i++)
    {
        printf("Enter the size of memory %d", i + 1);
        scanf("%d", &memory_size[i]);
        memory_process[i] = -1;
    }
    for (int j = 0; j < number; j++)
    {
        max = memory_size[0];
        loc = 0;
        for (i = 0; i < memory; i++)
        {
            if (max < memory_size[i])
            {
                max = memory_size[i];
                loc = i;
            }
        }
        if (size[j] <= max)
        {
            printf("process %d is allocated at %d", i, max);
            memory_size[loc] = memory_size[loc] - size[i];
        }
        else
            printf("process %d is not allocated at ", i);
    }
}