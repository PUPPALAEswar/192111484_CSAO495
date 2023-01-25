#include <stdio.h>
#include <unistd.h>
int main() {
	pid_t pid;
	pid = getpid();
	printf("This process's pid is : %d\n", pid);
	pid = getpid();
	printf("The parent process's pid is : %d\n", pid);
	int new_pid ;
	if (new_pid == 0) {
		printf("Child process created\n");
		printf("Child process's pid is : %d\n", getpid());
	} else {
		printf("Parent process created\n");
		printf("Parent process's pid is : %d\n", getpid());
	}
	return 0;
}
