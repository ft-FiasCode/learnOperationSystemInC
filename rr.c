#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int finished;
};

void calculateRR(struct Process p[], int n, int time_quantum) {
    int time = 0;
    int complete = 0;
    
    printf("\nGantt Chart (Time Quantum = %d):\n", time_quantum);
    
    while(complete != n) {
        int found = 0;
        
        for(int i = 0; i < n; i++) {
            // Check if process has arrived and has remaining time
            if(p[i].arrival_time <= time && p[i].remaining_time > 0 && !p[i].finished) {
                found = 1;
                p[i].finished = 1;  // Mark as executing
                
                // Execute for min(remaining_time, time_quantum)
                int exec_time = (p[i].remaining_time > time_quantum) ? time_quantum : p[i].remaining_time;
                
                for(int j = 0; j < exec_time; j++) {
                    printf("P%d ", p[i].pid);
                }
                time += exec_time;
                p[i].remaining_time -= exec_time;
                
                // Process completed
                if(p[i].remaining_time <= 0) {
                    complete++;
                    p[i].completion_time = time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                }
                break;
            }
        }
        
        if(!found) {
            printf("IDLE ");
            time++;
        }
    }
    printf("\n");
}

int main() {
    int n, time_quantum;
    struct Process p[10];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].finished = 0;
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
    
    calculateRR(p, n, time_quantum);
    
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
