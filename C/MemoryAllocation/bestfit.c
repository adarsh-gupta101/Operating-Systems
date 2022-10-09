// Best fit
// Created: 2015-08-26 20:00:00

#include <stdio.h>

void main()
{
    printf("Enter the number of process");
    int number,loc;
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

//     // for (i = 0; i < number; i++)
//     // {
//     //     int min = memory_size[0];
//     //     int loc = 0;
//     //     for (int j = 0; j < memory; j++)
//     //     {
//     //         if (min > memory_size[j])
//     //         {
//     //             min = memory_size[j];
//     //             loc = j;
//     //         }
//     //     }
//     //     if (size[i] <= min){
//     //         printf("Process %d is allocated to memory %d", i + 1, loc + 1);
//     //         memory_size[loc] = memory_size[loc] - size[i];
//     //     }
//     //     else
//     //         printf("Process %d is not allocated", i + 1);
//     // }
// .


    for(i=0;i<number;i++){
        int best=-1;
        for(int j=0;j<memory;j++){
            if(memory_size[j]>=size[i]){
                if(best==-1){
                    best=j;
                }
                else if(memory_size[best]>memory_size[j]){
                    best=j;
                }
            }
        }
        if(best!=-1){
            printf("Process %d is allocated to memory %d", i + 1, best + 1);
            memory_size[best] = memory_size[best] - size[i];
        }
        else
            printf("Process %d is not allocated", i + 1);
    }
}
