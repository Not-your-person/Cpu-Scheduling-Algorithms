#include <stdio.h>
#include "scheduling.h"  

int main() {
    int n, choice, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("\nEnter Arrival Time and Burst Time and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("P%d Priority:", i+1);
        scanf("%d",&p[i].priority);
    }

    printf("\nEnter Time Quantum (for RR): ");
    scanf("%d", &tq);

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. FCFS\n2. SJF \n3. Priority\n4. Round Robin\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: fcfs(p, n); break;
        case 2: sjf_non_preemptive(p, n); break;
        case 3: priority_scheduling(p, n); break;
        case 4: round_robin(p, n, tq); break;
        default: printf("Invalid choice.\n");
    }

    return 0;
}
