// Shared Memory

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include<stdlib.h>

void main()
{

    void *shared_memory = (void *)0;
    char buffer[100];
    int shmid;
    shmid = shmget((key_t)1234, 2048, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        printf("shmget failed\n");
        exit(0);
    }
    printf("shmid = %d\n", shmid);
    shared_memory = shmat(shmid, (void *)0, 0);
    printf("Memory attached at %p", shared_memory);
    printf("Enter some text: ");
    fgets(buffer, 100, stdin);
    strncpy(shared_memory, buffer, 100);
    printf("You wrote: %s\n", (char *)shared_memory);
    shmdt(shared_memory);
}
