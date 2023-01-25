#include <stdio.h>
#define quantum 3
int main() {
	int n,i,j,temp,remain;
	int wait_time=0,turnaround_time=0;
	int at[10],bt[10],rt[10];
	printf("Enter Total Process:\t ");
	scanf("%d",&n);
	remain=n;
	for(i=0; i<n; i++) {
		printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

	for(i=0,j=0; remain!=0;) {
		if(rt[j]<=quantum && rt[j]>0) {
			i+=rt[j];
			rt[j]=0;
			temp=1;
		} else if(rt[j]>0) {
			rt[j]-=quantum;
			i+=quantum;
		}
		if(rt[j]==0 && temp==1) {
			remain--;
			printf("P[%d]\t|\t%d\t|\t%d\n",j+1,i-at[j],i-at[j]-bt[j]);
			wait_time+=i-at[j]-bt[j];
			turnaround_time+=i-at[j];
			temp=0;
		}
		if(j==n-1)
			j=0;
		else if(at[j+1]<=i)
			j++;
		else
			j=0;
	}
	printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
	printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
	return 0;
}
