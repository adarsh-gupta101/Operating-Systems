#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

//IPC reader
void main(){
    int shmid=shmget((key_t)1234, 2048, 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        printf("shmget failed\n");
        exit(0);
    }
    printf("shmid = %d\n", shmid);
    void *shared_memory = shmat(shmid, (void *)0, 0);
    printf("Memory attached at %p", shared_memory);
    char *buffer=(char *)shared_memory;
    printf("You wrote: %s\n", buffer);
    shmdt(shared_memory);


}