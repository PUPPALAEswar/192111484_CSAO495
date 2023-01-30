#include <stdio.h>
#include <sys/stat.h>

int main() {
	char file_name[100];
	mode_t mode;

	printf("Enter file name: ");
	scanf("%s", file_name);

	printf("Enter permission mode in octal: ");
	scanf("%o", &mode);

	if (chmod(file_name, mode) == -1) {
		perror("chmod");
		return 1;
	}

	return 0;
}
