#include<stdio.h>
#include <math.h>
#define MAX 100
int main() {
	int n, head, track[MAX], diff[MAX];
	printf("Enter the number of disk requests: ");
	scanf("%d", &n);
	printf("Enter the positions of disk requests: \n");
	for(int i = 0; i < n; i++)
		scanf("%d", &track[i]);
	printf("Enter the initial head position: ");
	scanf("%d", &head);
	for(int i = 0; i < n; i++)
		diff[i] = abs(head - track[i]);
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(diff[j] > diff[j + 1]) {
				int temp = diff[j];
				diff[j] = diff[j + 1];
				diff[j + 1] = temp;
				temp = track[j];
				track[j] = track[j + 1];
				track[j + 1] = temp;
			}
	int start = 0;
	while(track[start] <= head)
		start++;
	printf("Tracks in order of their scan: \n");
	for(int i = start; i < n; i++)
		printf("%d ", track[i]);
	printf("%d ", 199);
	for(int i = 0; i < start; i++)
		printf("%d ", track[i]);

	return 0;
}
