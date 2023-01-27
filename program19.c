#include <pthread.h>
#include <stdio.h>
pthread_mutex_t lock;
int shared_variable;
void* thread_function(void* arg) {
	pthread_mutex_lock(&lock);
	shared_variable++;
	printf("Thread %lu: Shared variable: %d\n", (pthread_t)arg, shared_variable);
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main() {
	int num_threads;
	printf("Enter the number of threads: ");
	scanf("%d", &num_threads);
	pthread_t threads[num_threads];
	pthread_mutex_init(&lock, NULL);
	for (int i = 0; i < num_threads; i++) {
		pthread_create(&threads[i], NULL, thread_function, (void*)i);
	}
	for (int i = 0; i < num_threads; i++) {
		pthread_join(threads[i], NULL);
	}
	pthread_mutex_destroy(&lock);
	printf("Final value of shared variable: %d\n", shared_variable);
	return 0;
}
