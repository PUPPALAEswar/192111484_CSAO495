#include <stdio.h>

struct Process {

	int id;	int burst_time;

};

int main() {

	int n = 4;

	struct Process processes[n];

	processes[0].id = 1;

	processes[0].burst_time = 24;

	processes[1].id = 0;

	processes[1].burst_time = 3;

	processes[2].id = 3;

	processes[2].burst_time = 3;

	processes[3].id = 4;

	processes[3].burst_time = 12;

	int i, j;

	for (i = 0; i < n-1; i++) {

		for (j = 0; j < n-i-1; j++) {

			if (processes[j].burst_time > processes[j+1].burst_time) {

				struct Process temp =

processes[j];

				processes[j] = processes[j+1];

				processes[j+1] = temp;

			}

		}

	}

	printf("Process ID\tBurst Time\n");

	for (i = 0; i < n; i++) {

		printf("%d\t\t%d\n", processes[i].id, processes[i].burst_time);

	}

	return 0;

}
				
			

		

	

	
	
		
	



