#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
	int fd;
	char *filename;
	printf("Enter the filename: ");
	scanf("%s", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("Error opening file.\n");
		exit(1);
	}
	char buffer[256];
	int bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1) {
		printf("Error reading file.\n");
		exit(1);
	}
	printf("%s\n", buffer);
	int status = close(fd);
	if (status == -1) {
		printf("Error closing file.\n");
		exit(1);
	}
	return 0;
}
