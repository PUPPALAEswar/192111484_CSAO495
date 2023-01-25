#include <stdio.h>

#include <unistd.h>

#include <fcntl.h>

int main(int argc, char *argv[]) {

	int fd1, fd2;	char buffer[1024];

	ssize_t nread;

	fd1 = open(argv[1], O_RDONLY);

	fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);

	while ((nread = read(fd1, buffer, sizeof buffer)) > 0) {

		write(fd2, buffer, nread);

	}

	close(fd1);

	close(fd2);

	return 0;

}
