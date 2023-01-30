#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void *thread_func(void *arg) {
	printf("Inside new thread\n");
	sleep(1);
	pthread_t current_thread = pthread_self();
	if (pthread_equal(current_thread, *(pthread_t*)arg))
		printf("Threads are equal\n");
	else
		printf("Threads are not equal\n");
	pthread_exit(NULL);
}

int main() {
	char path[100];
	printf("Enter a directory path: ");
	scanf("%s", path);
	DIR *d = opendir(path);
	if (d) {
		struct dirent *dir;
		while ((dir = readdir(d)) != NULL)
			printf("%s\n", dir->d_name);
		closedir(d);
	}

	pthread_t new_thread, main_thread = pthread_self();
	pthread_create(&new_thread, NULL, thread_func, &main_thread);
	printf("Inside main thread\n");
	pthread_join(new_thread, NULL);
	printf("New thread has completed\n");
	return 0;
}
