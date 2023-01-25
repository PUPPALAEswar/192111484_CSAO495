#include <stdio.h>
struct process {
	int id;
	int burst_time;
};
int main() {
	struct process p[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
	int n = sizeof(p) / sizeof(p[0]), i, j, min, min_index=0;
	for (i = 0; i < n-1; i++) {
		min = p[i].burst_time;
		for (j = i+1; j < n; j++) {
			if (p[j].burst_time < min) {
				min = p[j].burst_time;
				min_index = j;
			}
		}
		if (min_index != i) {
			struct process temp = p[i];
			p[i] = p[min_index];
			p[min_index] = temp;
}
	}
	for (i = 0; i < n; i++) {
		printf("Process %d (burst time = %d)\n", p[i].id, p[i].burst_time);
	}
	return 0;
}
