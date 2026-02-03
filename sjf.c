#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void calculateSJF(struct Process p[], int n) {
    int complete = 0, time = 0, shortest = 0, min = 9999;
    
    // Initialize remaining time
    for(int i = 0; i < n; i++) {
        p[i].remaining_time = p[i].burst_time;
    }
    
    printf("\nGantt Chart:\n");
    printf("Time: ");
    
    while(complete != n) {
        // Find process with shortest remaining time among arrived processes
        min = 9999;
        for(int i = 0; i < n; i++) {
            if((p[i].arrival_time <= time) && (p[i].remaining_time > 0) && 
               (p[i].remaining_time < min)) {
                min = p[i].remaining_time;
                shortest = i;
            }
        }
        
        if(min == 9999) {
            printf("IDLE ");
            time++;
            continue;
        }
        
        // Reduce remaining time and execute process
        p[shortest].remaining_time--;
        printf("P%d ", p[shortest].pid);
        time++;
        
        // Check if process completed
        if(p[shortest].remaining_time == 0) {
            complete++;
            p[shortest].completion_time = time;
            p[shortest].turnaround_time = p[shortest].completion_time - p[shortest].arrival_time;
            p[shortest].waiting_time = p[shortest].turnaround_time - p[shortest].burst_time;
        }
    }
    printf("\n");
}

int main() {
    int n;
    struct Process p[10];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }
    
    calculateSJF(p, n);
    
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
    
    return 0;
}
