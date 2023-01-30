#include <stdio.h>
#include <string.h>
int main() {
  char pattern[100], text[1000];
  printf("Enter pattern to search: ");
  scanf("%s", pattern);
  printf("Enter text: ");
  scanf(" %[^\n]s", text);
  if (strstr(text, pattern)) {
    printf("Pattern found in the text\n");
  } else {
    printf("Pattern not found in the text\n");
  }
  return 0;
}
