#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

sem_t mutex, full, empty;
int buffer[10], count = 0;

void *producer()
{
    sem_wait(&empty);
    printf("Producer is waiting for empty semaphore\n");
    while (1)
    {
        int item = count + 10;
        if (count == 10)
        {
            count--;
            printf("Buffer is full\n");
            break;
        }
        else
        {
            buffer[count] = item;
            count++;
            printf("Producer produced item %d\n", item);
        }
        sleep(1);
    }
    sem_post(&full);
}

void *consumer()
{
    sem_wait(&full);
    printf("Consumer is waiting for full semaphore\n");
    while (1)
    {
        if (count == 0)
        {
            printf("Buffer is empty\n");
            break;
        }
        else
        {
            int item = buffer[count];
            printf("Consumer consumed item %d  \t\t %d\n", item, count);

            count--;
        }
        sleep(1);

    }
    sem_post(&empty);
}

void main(){
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    pthread_t arr[2];
    pthread_create(&arr[0], NULL, producer, NULL);
    pthread_create(&arr[1], NULL, consumer, NULL);
    for(int i=0;i<2;i++){
        pthread_join(arr[i], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);

}