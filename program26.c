#include <stdio.h>
#include <string.h>

int main() {
  char filename[100], operation[10];
  printf("Enter filename: ");
  scanf("%s", filename);
  printf("Enter operation (read/write): ");
  scanf("%s", operation);

  FILE *fp;
  if (!strcmp(operation, "write")) {
    fp = fopen(filename, "w");
    if (fp == NULL) {
      printf("Error opening file!\n");
      return 1;
    }
    fprintf(fp, "This is a sample write operation.");
    printf("Write successful.\n");
  } else if (!strcmp(operation, "read")) {
    fp = fopen(filename, "r");
    if (fp == NULL) {
      printf("Error opening file!\n");
      return 1;
    }
    char data[100];
    fscanf(fp, "%s", data);
    printf("Read from file: %s\n", data);
  } else {
    printf("Invalid operation.\n");
    return 1;
  }
  fclose(fp);
  return 0;
}
