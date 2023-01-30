#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
int main() {
    int fd;
    struct stat fileStat;
    DIR *dir;
    struct dirent *ent;
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    if (fstat(fd, &fileStat) < 0) {
        perror("fstat");
        return 1;
    }
    if (lseek(fd, 10, SEEK_SET) < 0) {
        perror("lseek");
        return 1;
    }
    printf("Information for %s\n", "example.txt");
    printf("---------------------------\n");
    printf("File Descriptor: %d\n", fd);
    printf("File Size: %d bytes\n", (int)fileStat.st_size);
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);
    close(fd);
    return 0;
}
