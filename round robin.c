#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int tq) {
    int rem_bt[n];  // Remaining burst times
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;  // Current time

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;  // There’s still a process left

                if (rem_bt[i] > tq) {
                    t += tq;           // Increase current time
                    rem_bt[i] -= tq;   // Decrease remaining time
                } else {
                    t += rem_bt[i];     // Process finished
                    wt[i] = t - bt[i];  // Waiting time
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void findTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findCompletionTime(int n, int tat[], int ct[]) {
    for (int i = 0; i < n; i++)
        ct[i] = tat[i];  // Assuming all processes arrive at time 0
}

void findAvgTime(int n, int bt[], int tq) {
    int wt[n], tat[n], ct[n];
    findWaitingTime(n, bt, wt, tq);
    findTurnaroundTime(n, bt, wt, tat);
    findCompletionTime(n, tat, ct);

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst\tWaiting\tTurnaround\tCompletion\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i], ct[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
}

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    findAvgTime(n, bt, tq);
    return 0;
}
