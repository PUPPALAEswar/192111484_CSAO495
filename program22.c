#include <stdio.h>
#define MAX 100

int main() {
	int blockSize[MAX], processSize[MAX], m, n, allocation[MAX], i, j;

	printf("Enter the number of blocks: ");
	scanf("%d", &m);
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	printf("Enter the size of the blocks:\n");
	for(i = 0; i < m; i++) {
		scanf("%d", &blockSize[i]);
	}

	printf("Enter the size of the processes:\n");
	for(i = 0; i < n; i++) {
		scanf("%d", &processSize[i]);
	}

	for(i = 0; i < n; i++) {
		int min = 99999;
		int bestFit = -1;
		for(j = 0; j < m; j++) {
			if(blockSize[j] >= processSize[i]) {
				if(min > blockSize[j] - processSize[i]) {
					min = blockSize[j] - processSize[i];
					bestFit = j;
				}
			}
		}

		if(bestFit != -1) {
			allocation[bestFit] = i;
			blockSize[bestFit] -= processSize[i];
		}
	}

	printf("\nBlock no.\tBlock size\tProcess no.\tProcess size");
	for(i = 0; i < m; i++) {
		printf("\n%d\t\t%d\t\t", i + 1, blockSize[i]);
		if(allocation[i] != -1) {
			printf("%d\t\t%d", allocation[i] + 1, processSize[allocation[i]]);
		} else {
			printf("Not allocated");
		}
	}

	return 0;
}
