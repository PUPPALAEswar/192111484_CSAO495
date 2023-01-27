#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, writeblock;
int data = 0, readerCount = 0;

void *reader(void *arg)
{
    int f;
    f = ((int)arg);
    sem_wait(&mutex);
    readerCount++;
    if(readerCount==1)
    {
        sem_wait(&writeblock);
    }
    sem_post(&mutex);
    printf("Data read by the reader%d is %d\n",f,data);
    sleep(1);
    sem_wait(&mutex);
    readerCount--;
    if(readerCount==0)
    {
        sem_post(&writeblock);
    }
    sem_post(&mutex);
}

void *writer(void *arg)
{
    int f;
    f = ((int) arg);
    sem_wait(&writeblock);
    data++;
    printf("Data writen by the writer%d is %d\n",f,data);
    sleep(1);
    sem_post(&writeblock);
}

int main()
{
    int i, b;
    pthread_t rtid[5],wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);
    printf("Enter the number of readers: ");
    scanf("%d", &b);
    for(i = 0; i < b; i++)
    {
        pthread_create(&rtid[i], NULL, reader, (void *)i);
    }
    printf("Enter the number of writers: ");
    scanf("%d", &b);
    for(i = 0; i < b; i++)
    {
        pthread_create(&wtid[i], NULL, writer, (void *)i);
    }
    for(i = 0; i < b; i++)
    {
        pthread_join(rtid[i], NULL);
        pthread_join(wtid[i], NULL);
    }
	return 0;
}
