#ifndef SCHEDULING_H
#define SCHEDULING_H

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void sortByArrival(struct Process p[], int n);
void printGanttChart(struct Process p[], int n);
void printProcessTable(struct Process p[], int n, int show_priority);
void printAverages(struct Process p[], int n);
void fcfs(struct Process p[], int n);
void sjf_non_preemptive(struct Process p[], int n);

void priority_scheduling(struct Process p[], int n);
void round_robin(struct Process p[], int n, int tq);

#endif