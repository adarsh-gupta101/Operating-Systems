#include <stdio.h>

void main()
{

    int number, flag;
    printf("Enter the number of process");
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

    for (i = 0; i < memory; i++)
    {
        printf("Enter the size of memory %d", i + 1);
        scanf("%d", &memory_size[i]);
    }

    for (i = 0; i < number; i++)
    {
        flag = 0;

        for (int j = 0; j < memory; j++)
        {
            if (size[i] < memory_size[j])
            {
                printf("Process %d is allocated to memory %d", i + 1, j + 1);
                memory_size[j] = memory_size[j] - size[i];
                flag = 1;
                break;
            }
            if (flag = 0)
            {
                printf("Process %d is not allocated", i + 1);
            }
        }
    }
}