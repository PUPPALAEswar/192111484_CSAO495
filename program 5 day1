#include <stdio.h>
struct Process {
    int priority;
    int pid;
};
int main() {
    struct Process processes[] = {{4, 1}, {3, 2}, {5, 3}};
    int n = sizeof(processes)/sizeof(processes[0]);
    int max_priority = 0, max_pid = 0;
    for (int i = 0; i < n; i++)
    if (processes[i].priority > max_priority) {
        max_priority = processes[i].priority;
        max_pid = processes[i].pid;
    }
    printf("PID: %d, Priority: %d\n", max_pid, max_priority);
    return 0;
}
