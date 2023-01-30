#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 50

int main(void) {
	int f[MAX_BLOCKS] = {0};
	int p, i, st, len, j, c;
	int k, a;

	printf("Enter how many blocks already allocated: ");
	if (scanf("%d", &p) != 1) {
		printf("Invalid input\n");
		return 1;
	}

	printf("Enter blocks already allocated: ");
	for (i = 0; i < p; i++) {
		if (scanf("%d", &a) != 1) {
			printf("Invalid input\n");
			return 1;
		}
		f[a] = 1;
	}

	while (1) {
		printf("Enter index of starting block and length: ");
		if (scanf("%d%d", &st, &len) != 2) {
			printf("Invalid input\n");
			return 1;
		}

		k = len;
		if (f[st] == 0) {
			for (j = st; j < st + k; j++) {
				if (f[j] == 0) {
					f[j] = 1;
					printf("%d --> %d\n", j, f[j]);
				} else {
					printf("Block %d is already allocated\n", j);
					k++;
				}
			}
		} else {
			printf("Starting block %d is already allocated\n", st);
		}

		printf("Do you want to enter more files (Yes - 1/No - 0)? ");
		if (scanf("%d", &c) != 1) {
			printf("Invalid input\n");
			return 1;
		}
		if (c == 0) {
			break;
		}
	}

	return 0;
}
