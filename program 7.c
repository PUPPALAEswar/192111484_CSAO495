#include<stdio.h>
struct Process {
	int pid;
	int burst_time;
} p[10];

int main() {
	int n,i,j;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the burst time of each process: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i].burst_time);
		p[i].pid = i + 1;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (p[j].burst_time > p[j+1].burst_time) {
				struct Process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	int wt = 0, tat = 0;
	for (i = 0; i < n; i++) {
		wt += p[i].burst_time;
		tat += wt;
	}
	printf("Avg waiting time = %f\n", (float)wt / n);
	printf("Avg turnaround time = %f\n", (float)tat / n);
	return 0;
}
