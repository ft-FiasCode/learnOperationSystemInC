#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void calculateFCFS(struct Process p[], int n) {
    // Sort by arrival time (FCFS processes in order received)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    
    // Calculate completion, turnaround, and waiting times
    p[0].completion_time = p[0].arrival_time + p[0].burst_time;
    p[0].turnaround_time = p[0].completion_time - p[0].arrival_time;
    p[0].waiting_time = p[0].turnaround_time - p[0].burst_time;
    
    for(int i = 1; i < n; i++) {
        p[i].completion_time = p[i-1].completion_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

void printGanttChart(struct Process p[], int n) {
    printf("\nGANTT CHART:\n");
    printf("+");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p[i].burst_time; j++) printf("-");
        printf("+");
    }
    printf("\n|");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p[i].burst_time-1; j++) printf(" ");
        printf("P%d", p[i].pid);
        for(int j = 0; j < p[i].burst_time-1; j++) printf(" ");
        printf("|");
    }
    printf("\n+");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p[i].burst_time; j++) printf("-");
        printf("+");
    }
    printf("\n");
    
    // Print timeline
    printf("0");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p[i].burst_time; j++) printf(" ");
        printf("%d", p[i].completion_time);
    }
    printf("\n");
}

int main() {
    int n;
    struct Process p[10];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &p[i].burst_time);
    }
    
    calculateFCFS(p, n);
    
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-------------------------------------\n");
    
    float total_tat = 0, total_wt = 0;
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
        total_tat += p[i].turnaround_time;
        total_wt += p[i].waiting_time;
    }
    
    printf("\nAverage Turnaround Time: %.2f", total_tat/n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt/n);
    
    printGanttChart(p, n);
    
    return 0;
}
