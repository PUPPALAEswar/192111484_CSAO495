#include <stdio.h>
#include <math.h>

#define MAX_TRACKS 200

void scan(int head, int tracks[], int n) {
	int i, j, seek_time = 0, left_size = 0, right_size = 0;
	int left[MAX_TRACKS], right[MAX_TRACKS];

	for (i = 0; i < n; i++) {
		if (tracks[i] < head)
			left[left_size++] = tracks[i];
		else
			right[right_size++] = tracks[i];
	}
	for (i = 0; i < left_size - 1; i++)
		for (j = 0; j < left_size - i - 1; j++)
			if (left[j] > left[j + 1]) {
				int temp = left[j];
				left[j] = left[j + 1];
				left[j + 1] = temp;
			}
	for (i = 0; i < right_size - 1; i++)
		for (j = 0; j < right_size - i - 1; j++)
			if (right[j] < right[j + 1]) {
				int temp = right[j];
				right[j] = right[j + 1];
				right[j + 1] = temp;
			}
	for (i = 0; i < left_size; i++) {
		seek_time += abs(head - left[i]);
		head = left[i];
		printf("%d ", head);
	}
	for (i = 0; i < right_size; i++) {
		seek_time += abs(head - right[i]);
		head = right[i];
		printf("%d ", head);
	}
	printf("\nTotal seek time is %d\n", seek_time);
}

int main() {
	int n, head, tracks[MAX_TRACKS];

	printf("Enter the head position: ");
	scanf("%d", &head);
	printf("Enter the number of tracks: ");
	scanf("%d", &n);
	printf("Enter the tracks: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &tracks[i]);

	printf("Order of tracks: ");
	scan(head, tracks, n);
	return 0;
}
