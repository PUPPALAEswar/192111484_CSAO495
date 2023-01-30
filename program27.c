#include <stdio.h>
#include <dirent.h>
int main() {
	char directory[100];
	printf("Enter the directory name: ");
	scanf("%s", directory);

	DIR *dir = opendir(directory);
	if (dir == NULL) {
		printf("Error: Unable to open directory\n");
		return 1;
	}
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		printf("%s\n", entry->d_name);
	}
	closedir(dir);
	return 0;
}
