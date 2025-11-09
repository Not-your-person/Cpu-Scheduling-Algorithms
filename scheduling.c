#include <stdio.h>
#include <limits.h>
#include "scheduling.h"
#include<string.h>

void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void printGanttChart(struct Process p[], int n) {
    int i, j;
    int max_pid_len = 4;
    

    for (i = 0; i < n; i++) {
        char temp[20];
        sprintf(temp, "P%d", p[i].pid);
        int len = strlen(temp);
        if (len > max_pid_len) max_pid_len = len;
    }
    max_pid_len += 2; 
    
    printf("\n");
    printf("=============================================================================\n");
    printf("                              Gantt Chart                                    \n");
    printf("=============================================================================\n\n");
    

    int max_time = p[n-1].completion_time;
    int time_unit = 2; 

    printf("%-*s", max_pid_len, "Process");
    printf("|");
    for (i = 0; i <= max_time; i++) {
        if (i % 5 == 0) {
            printf("%-4d", i);
        } else {
            printf("  ");
        }
    }
    printf("\n");
    
  
    printf("%-*s", max_pid_len, "");
    printf("|");
    for (i = 0; i <= max_time * time_unit; i++) {
        printf("-");
    }
    printf("\n");
    
    int prev_end = 0;
    for (i = 0; i < n; i++) {
        int process_start = (i == 0) ? p[i].arrival_time : 
                           (p[i].arrival_time > prev_end ? p[i].arrival_time : prev_end);
        int burst_duration = p[i].completion_time - process_start;
        
       
        printf("P%-*d", max_pid_len - 1, p[i].pid);
        printf("|");
   
        for (j = 0; j < process_start * time_unit; j++) {
            printf(" ");
        }
  
        for (j = 0; j < burst_duration * time_unit; j++) {
            printf("█");
        }
        
        printf("\n");
        
        prev_end = p[i].completion_time;
    }
    

    printf("%-*s", max_pid_len, "");
    printf("|");
    for (i = 0; i <= max_time * time_unit; i++) {
        printf("-");
    }
    printf("\n\n");
}

void printProcessTable(struct Process p[], int n, int show_priority) {
    if (show_priority) {
        printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
        for (int i = 0; i < n; i++) {
            printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
                   p[i].pid,
                   p[i].arrival_time,
                   p[i].burst_time,
                   p[i].priority,
                   p[i].completion_time,
                   p[i].turnaround_time,
                   p[i].waiting_time);
        }
    } else {
        printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
        for (int i = 0; i < n; i++) {
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                   p[i].pid,
                   p[i].arrival_time,
                   p[i].burst_time,
                   p[i].completion_time,
                   p[i].turnaround_time,
                   p[i].waiting_time);
        }
    }
}

void printAverages(struct Process p[], int n) {
    float total_wait = 0, total_turn = 0;
    
    for (int i = 0; i < n; i++) {
        total_wait += p[i].waiting_time;
        total_turn += p[i].turnaround_time;
    }
    
    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turn / n);
}

void fcfs(struct Process p[], int n) {
    int current_time = 0;

    sortByArrival(p, n);

    printf("\n--- FCFS Scheduling ---\n");
    
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;

        p[i].waiting_time = current_time - p[i].arrival_time;
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;

        current_time += p[i].burst_time;
    }
    
    printGanttChart(p, n);
    printProcessTable(p, n, 0);
    printAverages(p, n);
}

void sjf_non_preemptive(struct Process p[], int n)
{
    sortByArrival(p, n);

    int time = 0;
    int best;

    for (int i = 0; i < n; i++) {

        if (time < p[i].arrival_time)
            time = p[i].arrival_time;

        best = i; 

        for (int j = i + 1; j < n; j++) {

            if (p[j].arrival_time <= time + p[i].burst_time) {

                if (p[j].arrival_time < p[best].arrival_time ||
                   (p[j].arrival_time == p[best].arrival_time &&
                   (p[j].burst_time < p[best].burst_time ||
                   (p[j].burst_time == p[best].burst_time &&
                    p[j].pid < p[best].pid))))
                {
                    best = j;
                }

            } else {
                break;
            }
        }

        
        if (best != i) {
            struct Process temp = p[i];
            p[i] = p[best];
            p[best] = temp;
        }

        // Schedule p[i]
        
        time += p[i].burst_time;
        p[i].completion_time = time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }

    printGanttChart(p, n);
    printProcessTable(p, n, 0);
    printAverages(p, n);
}
void priority_scheduling(struct Process p[], int n)//smaller number means higher priority
{
    sortByArrival(p, n);

    int time = 0;
    int imp;

    for (int i = 0; i < n; i++) {

        if (time < p[i].arrival_time)
            time = p[i].arrival_time;

        imp = i; 

        for (int j = i + 1; j < n; j++) {

            if (p[j].arrival_time <= time) {

                if (p[j].priority < p[imp].priority ||
                   (p[j].priority == p[imp].priority &&
                   (p[j].arrival_time < p[imp].arrival_time ||
                   (p[j].arrival_time == p[imp].arrival_time &&
                    p[j].pid < p[imp].pid))))
                {
                    imp = j;
                }

            } else {
                break;
            }
        }

        
        if (imp != i) {
            struct Process temp = p[i];
            p[i] = p[imp];
            p[imp] = temp;
        }
        
        time += p[i].burst_time;
        p[i].completion_time = time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
    printGanttChart(p,n);
    printProcessTable(p,n,0);
    printAverages(p,n);
}
void round_robin(struct Process p[], int n, int tq)
{

    ;
}
