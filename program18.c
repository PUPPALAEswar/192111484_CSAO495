#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_ITEMS 10

int buffer[MAX_ITEMS];
int count = 0;
sem_t full, empty;
pthread_mutex_t mutex;

void *producer(void *arg) {
	int i = 0;
	for (i = 0; i < *((int *)arg); i++) {
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[count] = i;
		printf("Produced item %d\n", i);
		count++;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void *arg) {
	for (int i = 0; i < *((int *)arg); i++) {
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[count-1];
		printf("Consumed item %d\n", item);
		count--;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

int main() {
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, MAX_ITEMS);
	pthread_mutex_init(&mutex, NULL);
	pthread_t p, c;
	int user_input;
	printf("1.producer\n2.consumer\n3.exit\nEnter a number:");
	scanf("%d",&user_input);
	if(user_input == 1) {
		int num_items;
		printf("Enter the number of items to produce: ");
		scanf("%d", &num_items);
		pthread_create(&p, NULL, producer, &num_items);
		pthread_join(p, NULL);
	} else if(user_input == 2) {
		int num_items;
		printf("Enter the number of items to consume: ");
		scanf("%d", &num_items);
		pthread_create(&c, NULL, consumer, &num_items);
		pthread_join(c, NULL);
	} else if(user_input == 3) {
		return 0;
	}
	sem_destroy(&full);
	sem_destroy(&empty);
	pthread_mutex_destroy(&mutex);
	return 0;
}
