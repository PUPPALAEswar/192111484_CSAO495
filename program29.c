#include <dirent.h> 
#include <stdio.h> 
#include <string.h> 
int main(void) 
{ 
    DIR *d; 
    struct dirent *dir; 
    char path[100]; 
    printf("Enter a directory path: "); 
    scanf("%s", path); 
    d = opendir(path); 
    if (d) 
    { 
        while ((dir = readdir(d)) != NULL) 
            printf("%s\n", dir->d_name); 
        closedir(d); 
    } 
    return 0; 
} 
